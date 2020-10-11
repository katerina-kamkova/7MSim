//
// Created by yarkoe on 03.10.2020.
//

#ifndef DWACLIENT_SAFEQUEUE_H
#define DWACLIENT_SAFEQUEUE_H

#include <queue>
#include <mutex>
#include <condition_variable>

template<class T>
class SafeQueue {
public:
    SafeQueue();
    void enqueue(T t);
    T dequeue();

private:
    std::queue<T> queue;
    mutable std::mutex mutex;
    std::condition_variable conditionVariable;
};


template<class T>
void SafeQueue<T>::enqueue(T t) {
    std::lock_guard<std::mutex> lock(mutex);
    queue.push(t);
    conditionVariable.notify_one();
}

template<class T>
T SafeQueue<T>::dequeue() {
    std::unique_lock<std::mutex> lock(mutex);

    while (queue.empty())
    {
        conditionVariable.wait(lock);
    }

    T value = queue.front();
    queue.pop();

    return value;
}

template<class T>
SafeQueue<T>::SafeQueue()
        :   queue(),
            mutex(),
            conditionVariable()
{}


#endif //DWACLIENT_SAFEQUEUE_H
