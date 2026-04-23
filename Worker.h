#ifndef SS26_WORKER_H
#define SS26_WORKER_H

#include <mutex>

class Worker {
public:
    Worker(int start, int end, int value);

    int workFuture();
    void workMutex(int& result, std::mutex& mutex);
    void workIndividual(int& result);

private:
    int start;
    int end;
    int value;
};


#endif //SS26_WORKER_H
