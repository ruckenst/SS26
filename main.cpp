#include <iostream>
#include <mutex>
#include "ThreadPool.h"

void work(bool& isCancelled) {
    for(int i = 0; i < 100000000; i++) {
        if(isCancelled){
            std::cout << "Worker cancelled!" << std::endl;
            break;
        }

        std::cout << "Printing: " << i << std::endl;
    }
}

int main() {
    /*
    bool isCancelled;
    std::thread th1 = std::thread(work, std::ref(isCancelled));
    std::thread th2 = std::thread(work, std::ref(isCancelled));
    std::thread th3 = std::thread(work, std::ref(isCancelled));

    for(int i = 0; i < 1000; i++) {
        std::cout << "PRINTING: " << i << std::endl;
    }

    isCancelled = true;
    th1.join();
    th2.join();
    th3.join();
     */

    const int numberOfElements = 1000000000;
    const int numberOfThreads = 8;
    int numberOfElementsPerThread = numberOfElements / numberOfThreads;
    int remainingElements = numberOfElements % numberOfThreads;

    ThreadPool threadPool(2);

    auto start = std::chrono::steady_clock::now();

    for(int i = 0; i < numberOfThreads; i++) {
        int startValue = i * numberOfElementsPerThread;
        int endValue = (i + 1) * numberOfElementsPerThread;

        if(i + 1 == numberOfThreads){
            endValue += remainingElements;
        }

        threadPool.startFuture(startValue, endValue);
    }

    int result = threadPool.awaitFuture();

    auto end = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    std::cout << "Result: " << result << std::endl;
    std::cout << "Processing took: " << duration << "ms" << std::endl;

    return 0;
}