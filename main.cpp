#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>
#include <future>

int countElementsFuture(int start, int end, int value) {
    int result = 0;

    for(int i = start; i < end; i++) {
        if(i % value == 0) {
            result++;
        }
    }

    return result;
}

void countElements(int start, int end, int value, int& result) {
    for(int i = start; i < end; i++) {
        if(i % value == 0) {
            result++;
        }
    }
}

void countElementsMutex(int start, int end, int value, int& result, std::mutex& mutex) {
    for(int i = start; i < end; i++) {
        if(i % value == 0) {
            mutex.lock();
            result++;
            mutex.unlock();

            /*
             * while(mutex == true) {}
             *
             * mutex = true;
             * result++;
             * mutex = false;
             *
             */
        }
    }
}

int main() {
    int result = 0;

    // ============================================================

    auto startPoint = std::chrono::steady_clock::now();

    countElements(0, 1000000000, 82, result);

    auto endPoint = std::chrono::steady_clock::now();
    auto durationInMs = std::chrono::duration_cast<std::chrono::milliseconds>(endPoint - startPoint).count();

    std::cout << "Calculation took: " << durationInMs << "ms" << std::endl;
    std::cout << "Result: " << result << std::endl;

    // ============================================================

    result = 0;

    int resultT1 = 0;
    int resultT2 = 0;
    startPoint = std::chrono::steady_clock::now();

    std::thread t1 = std::thread(countElements, 0, 499999999, 82, std::ref(resultT1));
    std::thread t2 = std::thread(countElements, 500000000, 1000000000, 82, std::ref(resultT2));

    t1.join();
    t2.join();

    result = resultT1 + resultT2;

    endPoint = std::chrono::steady_clock::now();
    durationInMs = std::chrono::duration_cast<std::chrono::milliseconds>(endPoint - startPoint).count();

    std::cout << "Calculation took: " << durationInMs << "ms" << std::endl;
    std::cout << "Result: " << result << std::endl;

    // ============================================================

    result = 0;
    std::mutex mutex;
    startPoint = std::chrono::steady_clock::now();

    t1 = std::thread(countElementsMutex, 0, 499999999, 82, std::ref(result), std::ref(mutex));
    t2 = std::thread(countElementsMutex, 500000000, 1000000000, 82, std::ref(result), std::ref(mutex));

    t1.join();
    t2.join();

    endPoint = std::chrono::steady_clock::now();
    durationInMs = std::chrono::duration_cast<std::chrono::milliseconds>(endPoint - startPoint).count();

    std::cout << "Calculation took: " << durationInMs << "ms" << std::endl;
    std::cout << "Result: " << result << std::endl;

    // ============================================================

    result = 0;
    std::vector<std::thread> threads;
    const int numberOfThreads = 3;
    int numberOfElementsPerThread = 1000000000 / numberOfThreads;
    int processedNumberOfElements = 0;

    startPoint = std::chrono::steady_clock::now();

    for(int i = 0; i < numberOfThreads; i++) {
        int start = numberOfElementsPerThread * i;
        int end = numberOfElementsPerThread * (i + 1);

        processedNumberOfElements += numberOfElementsPerThread;

        if(i + 1 == numberOfThreads) {
            end += 1000000000 - processedNumberOfElements;
        }

        threads.push_back(std::thread(countElementsMutex, start, end, 82, std::ref(result), std::ref(mutex)));
    }

    for(auto& thread : threads) {
        thread.join();
    }

    threads.clear();

    endPoint = std::chrono::steady_clock::now();
    durationInMs = std::chrono::duration_cast<std::chrono::milliseconds>(endPoint - startPoint).count();

    std::cout << "Calculation took: " << durationInMs << "ms" << std::endl;
    std::cout << "Result: " << result << std::endl;

    // ============================================================

    result = 0;
    std::vector<std::future<int>> futures;
    const int numberOfFutures = 3;
    int numberOfElementsPerFuture = 1000000000 / numberOfFutures;
    processedNumberOfElements = 0;

    startPoint = std::chrono::steady_clock::now();

    for(int i = 0; i < numberOfFutures; i++) {
        int start = numberOfElementsPerFuture * i;
        int end = numberOfElementsPerFuture * (i + 1);

        processedNumberOfElements += numberOfElementsPerFuture;

        if(i + 1 == numberOfThreads) {
            end += 1000000000 - processedNumberOfElements;
        }

        futures.push_back(std::async(std::launch::async, countElementsFuture, start, end, 82));
    }

    for(auto& future : futures) {
        result += future.get();
    }

    futures.clear();

    endPoint = std::chrono::steady_clock::now();
    durationInMs = std::chrono::duration_cast<std::chrono::milliseconds>(endPoint - startPoint).count();

    std::cout << "Calculation took: " << durationInMs << "ms" << std::endl;
    std::cout << "Result: " << result << std::endl;

    return 0;
}