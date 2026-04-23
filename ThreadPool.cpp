#include "ThreadPool.h"

ThreadPool::ThreadPool(int value){
    this->value = value;
    this->result = 0;
}

void ThreadPool::startFuture(int start, int end) {
    workers.push_back(Worker(start, end, value));
    futures.push_back(std::async(std::launch::async, &Worker::workFuture, workers.back()));
}

int ThreadPool::awaitFuture() {
    int computedResult = 0;

    for(auto& future : futures) {
        computedResult += future.get();
    }

    futures.clear();
    workers.clear();

    return computedResult;
}

void ThreadPool::startMutex(int start, int end) {
    workers.push_back(Worker(start, end, value));
    threads.push_back(std::thread(&Worker::workMutex, workers.back(), std::ref(result), std::ref(mutex)));
}

int ThreadPool::awaitMutex() {
    for(auto& thread : threads) {
        thread.join();
    }

    threads.clear();
    workers.clear();

    return result;
}

// Funktioniert nicht, weil beim push-back vom results, die Speicheradressen
// verschoben werden
void ThreadPool::startIndividual(int start, int end) {
    workers.push_back(Worker(start, end, value));
    results.push_back(0);
    threads.push_back(std::thread(&Worker::workIndividual, workers.back(), std::ref(results.back())));
}

int ThreadPool::awaitIndividual() {
    for(auto& thread : threads) {
        thread.join();
    }

    threads.clear();
    workers.clear();

    int computedResult = 0;
    for(auto& result : results) {
        computedResult += result;
    }

    results.clear();
    return computedResult;
}