#include <bits/stdc++.h>
using namespace std;

// Abstract class
class Queue
{
public:
    virtual void info() = 0;
};

// Implementation
class MyQueue : public Queue
{
private:
    int *arr;
    int front;
    int rear;
    int length;
    int capacity;

public:
    MyQueue(int size);
    ~MyQueue();
    void enqueue(int);
    void dequeue();
    int size();
    int getFront();
    int getRear();
    bool isFull();
    bool isEmpty();

    /* =================== mandatory override =================== */
    void info() override
    {
        cout << "\nProgram to demonstrate abstraction and queue implementation\n";
    }
};

/* =================== constructor =================== */
MyQueue::MyQueue(int size)
{
    arr = new int[size];
    capacity = size;
    length = 0;
    front = 0;
    rear = size - 1;
}

/* =================== destructor =================== */
MyQueue::~MyQueue()
{
    delete[] arr;
}

/* ===================== push ===================== */
void MyQueue::enqueue(int val)
{
    if (isFull())
    {
        cout << "MyQueue full\n";
        exit(1);
    }

    rear = ((rear + 1) % capacity);
    arr[rear] = val;
    length++;
}

/* ===================== pop ===================== */
void MyQueue::dequeue()
{
    if (isEmpty())
    {
        cout << "MyQueue empty\n";
        exit(1);
    }

    front = ((front + 1) % capacity);
    length--;
}

/* ===================== size ===================== */
int MyQueue::size()
{
    return length + 1;
}

/* ===================== front ===================== */
int MyQueue::getFront()
{
    if (isEmpty())
    {
        cout << "MyQueue empty\n";
        exit(1);
    }

    return arr[front];
}

/* ===================== back ===================== */
int MyQueue::getRear()
{
    if (isEmpty())
    {
        cout << "MyQueue empty\n";
        exit(1);
    }

    return arr[rear];
}

/* ===================== empty ===================== */
bool MyQueue::isEmpty()
{
    return length == 0;
}

/* =================== check full ==================== */
bool MyQueue::isFull()
{
    return length == capacity;
}

// Driver code
int main()
{
    // create object
    MyQueue qu(10);
    qu.info();

    // perform operations
    qu.enqueue(1);
    qu.enqueue(2);
    qu.enqueue(2);
    qu.dequeue();
    qu.enqueue(4);

    // print result
    while (!qu.isEmpty())
    {
        cout << qu.getFront() << " ";
        qu.dequeue();
    }
}