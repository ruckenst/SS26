#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>
#include <vector>
#include <future>

int getNumberOfElementsFuture(int start, int end, int value) {
    int result = 0;

    for(int i = start; i < end; i++) {
        if(i % value == 0) {
            result++;
        }
    }

    return result;
}

void getNumberOfElements(int start, int end, int value, int& result) {
    for(int i = start; i < end; i++) {
        if(i % value == 0) {
            result++;
        }
    }
}

void getNumberOfElementsMutex(int start, int end, int value, int& result, std::mutex& mutex) {
    mutex.lock();
    for(int i = start; i < end; i++) {
        if(i % value == 0) {
            /*
             * while(locked) { }
             *
             * locked = true;
             * result++;
             * locked = false;
             */

            result++;
        }
    }

    mutex.unlock();
}



int main() {

    int result = 0;
    auto start = std::chrono::steady_clock::now();

    getNumberOfElements(0, 1000000000, 84, result);

    auto end = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    std::cout << "Result: " << result << std::endl;
    std::cout << "Processing took: " << duration << "ms" << std::endl;

    // ===============================================================================================

    int resultA = 0;
    int resultB = 0;
    start = std::chrono::steady_clock::now();

    std::thread th1 = std::thread(getNumberOfElements, 0, 499999999, 84, std::ref(resultA));
    std::thread th2 = std::thread(getNumberOfElements, 500000000, 1000000000, 84, std::ref(resultB));

    th1.join();
    th2.join();

    result = resultA + resultB;

    end = std::chrono::steady_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    std::cout << "Result: " << result << std::endl;
    std::cout << "Processing took: " << duration << "ms" << std::endl;

    // ===============================================================================================

    result = 0;
    std::mutex mutex;
    start = std::chrono::steady_clock::now();

    th1 = std::thread(getNumberOfElementsMutex, 0, 499999999, 84, std::ref(result), std::ref(mutex));
    th2 = std::thread(getNumberOfElementsMutex, 500000000, 1000000000, 84, std::ref(result), std::ref(mutex));

    th1.join();
    th2.join();

    end = std::chrono::steady_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    std::cout << "Result: " << result << std::endl;
    std::cout << "Processing took: " << duration << "ms" << std::endl;

    // ===============================================================================================

    std::vector<std::future<int>> futures;
    const int numberOfFutures = 16;
    int numberOfElementsPerFuture = 1000000000 / numberOfFutures;
    int remainingElementsPerFuture = 1000000000 % numberOfFutures;
    result = 0;

    start = std::chrono::steady_clock::now();

    for(int i = 0; i < numberOfFutures; i++) {
        int startValue = i * numberOfElementsPerFuture;
        int endValue = (i + 1) * numberOfElementsPerFuture;

        if(i + 1 == numberOfFutures){
            endValue += remainingElementsPerFuture;
        }

        futures.push_back(std::async(std::launch::async, getNumberOfElementsFuture, startValue, endValue, 84));
    }

    for(auto& future : futures) {
        result += future.get();
    }

    end = std::chrono::steady_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    std::cout << "Result: " << result << std::endl;
    std::cout << "Processing took: " << duration << "ms" << std::endl;

    return 0;
}