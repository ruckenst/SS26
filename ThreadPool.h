#ifndef SS26_THREADPOOL_H
#define SS26_THREADPOOL_H

#include "Worker.h"
#include <vector>
#include <thread>
#include <future>
#include <mutex>

class ThreadPool {
public:
    ThreadPool(int value);

    /// For Futures
    void startFuture(int start, int end);
    int awaitFuture();

    /// For Individual Results
    void startMutex(int start, int end);
    int awaitMutex();

    /// For Individual Results
    void startIndividual(int start, int end);
    int awaitIndividual();

private:
    int value;
    std::vector<std::thread> threads;
    std::vector<Worker> workers;

    /// For Futures
    std::vector<std::future<int>> futures;

    /// For Shared Result
    int result;
    std::mutex mutex;

    /// For Individual Results
    std::vector<int> results;
};


#endif //SS26_THREADPOOL_H
