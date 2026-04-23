#ifndef SS26_THREADPOOL_H
#define SS26_THREADPOOL_H

#include <thread>
#include <future>
#include <vector>
#include <mutex>
#include "Worker.h"

class ThreadPool {
public:
    ThreadPool(int value);

    void startFuture(int start, int end);
    int awaitFuture();

    void startMutex(int start, int end);
    int awaitMutex();

    void startIndividual(int start, int end);
    int awaitIndividual();

private:
    int value;
    std::vector<std::thread> threads;
    std::vector<Worker> workers;

    /// For futures
    std::vector<std::future<int>> futures;

    /// For mutex results
    std::mutex mutex;
    int result;

    /// For individual results
    std::vector<int> results;
};


#endif //SS26_THREADPOOL_H
