#include "ThreadPool.h"

ThreadPool::ThreadPool(int value) {
    this->value = value;
    this->result = 0;
}

void ThreadPool::startFuture(int start, int end) {
    workers.push_back(Worker(start, end, value));
    futures.push_back(std::async(std::launch::async, &Worker::runFuture, workers.back()));
}

int ThreadPool::awaitFuture() {
    int returnValue = 0;
    for(auto& future : futures) {
        returnValue += future.get();
    }

    futures.clear();
    workers.clear();

    return returnValue;
}

void ThreadPool::startMutex(int start, int end) {
    workers.push_back(Worker(start, end, value));
    threads.push_back(std::thread(&Worker::runMutex, workers.back(), std::ref(result), std::ref(mutex)));
}

int ThreadPool::awaitMutex() {
    for(auto& thread : threads) {
        thread.join();
    }
    threads.clear();
    workers.clear();

    return result;
}

// So nicht möglich, da beim push_back ein realloc passieren kann, was alle bisherigen Referenzen zerschießt
// Dementsprechend müsste man vorher die größe der Threads wissen, oder ein Array mit einem Max-Thread-Count nutzen
void ThreadPool::startIndividual(int start, int end) {
    workers.push_back(Worker(start, end, value));
    results.push_back(0);
    threads.push_back(std::thread(&Worker::runIndividual, workers.back(), std::ref(results.back())));
}

int ThreadPool::awaitIndividual() {
    for(auto& thread : threads) {
        thread.join();
    }
    threads.clear();
    workers.clear();

    int sum = 0;
    for(auto& result : results) {
        sum += result;
    }
    results.clear();

    return sum;
}
