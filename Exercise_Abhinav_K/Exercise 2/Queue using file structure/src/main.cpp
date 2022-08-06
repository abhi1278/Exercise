#include <utility.h>

// Driver code
int main()
{
    // Create object with size
    Queue qu(10);

    // push and pop operations
    qu.enqueue(10);
    qu.enqueue(20);
    qu.enqueue(30);
    qu.enqueue(40);
    qu.dequeue();

    // print queue content
    while (!qu.isEmpty())
    {
        cout << qu.getFront() << " ";
        qu.dequeue();
    }
}