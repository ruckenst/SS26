#include <iostream>
#include <mutex>
#include "ThreadPool.h"
#include "Worker.h"
#include <thread>

void printTonsOfText(bool& isCancelled){
    for(int i = 0; i < 1000000000; i++) {
        if(isCancelled) {
            std::cout << "WORKER CANCELLED!" << std::endl;
            break;
        }

        std::cout << "Printing: " << i << std::endl;
    }
}

int main() {
    /*
    bool isCancelled;
    std::thread th1 = std::thread(printTonsOfText, std::ref(isCancelled));
    std::thread th2 = std::thread(printTonsOfText, std::ref(isCancelled));

    for(int i = 0; i < 1000; i++) {
        std::cout << "MAIN LOOP: " << i << std::endl;
    }

    std::cout << "MAIN LOOP FINISHED!!!" << std::endl;
    isCancelled = true;

    th1.join();
    th2.join();
     */

    int result = 0;

    std::vector<Worker> workers;
    const int numberOfTotalElements = 1000000000;
    const int numberOfThreads = 8;
    int numberOfElementsPerThread = numberOfTotalElements / numberOfThreads;
    int remainingElements = numberOfTotalElements % numberOfThreads;

    auto startPoint = std::chrono::steady_clock::now();

    ThreadPool threadPool(2);

    for(int i = 0; i < numberOfThreads; i++) {
        int start = numberOfElementsPerThread * i;
        int end = numberOfElementsPerThread * (i + 1);

        if(i + 1 == numberOfThreads) {
            end += remainingElements;
        }

        threadPool.startIndividual(start, end);
    }

    result = threadPool.awaitIndividual();

    auto endPoint = std::chrono::steady_clock::now();
    auto durationInMs = std::chrono::duration_cast<std::chrono::milliseconds>(endPoint - startPoint).count();

    std::cout << "Calculation took: " << durationInMs << "ms" << std::endl;
    std::cout << "Result: " << result << std::endl;

    return 0;
}