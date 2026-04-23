#ifndef SS26_WORKER_H
#define SS26_WORKER_H

#include <mutex>

class Worker {
public:
    Worker(int start, int end, int value);

    /// For futures
    int runFuture();

    /// For threads with shared result
    void runMutex(int& result, std::mutex& mutex);

    /// For threads with individual results
    void runIndividual(int& result);

private:
    int start;
    int end;
    int value;
};


#endif //SS26_WORKER_H
