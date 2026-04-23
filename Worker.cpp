#include "Worker.h"

Worker::Worker(int start, int end, int value) {
    this->start = start;
    this->end = end;
    this->value = value;
}

int Worker::workFuture() {
    int result = 0;

    for(int i = start; i < end; i++) {
        if(i % value == 0) {
            result++;
        }
    }

    return result;
}

void Worker::workMutex(int &result, std::mutex& mutex) {
    for(int i = start; i < end; i++) {
        if(i % value == 0) {
            mutex.lock();
            result++;
            mutex.unlock();
        }
    }
}

void Worker::workIndividual(int &result) {
    for(int i = start; i < end; i++) {
        if(i % value == 0) {
            result++;
        }
    }
}