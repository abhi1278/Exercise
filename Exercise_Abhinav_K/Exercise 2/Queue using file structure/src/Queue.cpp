#include <utility.h>

/* =================== constructor =================== */
Queue::Queue(int size)
{
    arr = new int[size];
    capacity = size;
    length = 0;
    front = 0;
    rear = size - 1;
}

/* =================== destructor =================== */
Queue::~Queue()
{
    delete[] arr;
}

/* ===================== push ===================== */
void Queue::enqueue(int val)
{
    if (isFull())
    {
        cout << "Queue full\n";
        exit(1);
    }

    rear = ((rear + 1) % capacity);
    arr[rear] = val;
    length++;
}

/* ===================== pop ===================== */
void Queue::dequeue()
{
    if (isEmpty())
    {
        cout << "Queue empty\n";
        exit(1);
    }

    front = ((front + 1) % capacity);
    length--;
}

/* ===================== size ===================== */
int Queue::size()
{
    return length + 1;
}

/* ===================== front ===================== */
int Queue::getFront()
{
    if (isEmpty())
    {
        cout << "Queue empty\n";
        exit(1);
    }

    return arr[front];
}

/* ===================== back ===================== */
int Queue::getRear()
{
    if (isEmpty())
    {
        cout << "Queue empty\n";
        exit(1);
    }

    return arr[rear];
}

/* ===================== empty ===================== */
bool Queue::isEmpty()
{
    return length == 0;
}

/* =================== check full ==================== */
bool Queue::isFull()
{
    return length == capacity;
}
