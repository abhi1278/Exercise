#ifndef __QUEUE_H_
#define __QUEUE_H_
#include <utility.h>

// declaration of class
using namespace std;

class Queue
{
private:
    int *arr;
    int front;
    int rear;
    int length;
    int capacity;

public:
    Queue(int size);
    ~Queue();
    void enqueue(int);
    void dequeue();
    int size();
    int getFront();
    int getRear();
    bool isFull();
    bool isEmpty();
};

#endif