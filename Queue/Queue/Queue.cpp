#include <iostream>
#include "Queue.h"

using namespace std;

int main()
{
    Queue arr = Queue(5);

    arr.enqueue(1);
    arr.enqueue(2);
    arr.enqueue(3);
    arr.enqueue(4);
    arr.enqueue(5);
    cout << arr.dequeue() << endl;
    cout << arr.dequeue() << endl;
    cout << arr.dequeue() << endl;
    arr.enqueue(9);
    arr.enqueue(7);
    arr.enqueue(10);
    cout << arr.dequeue() << endl;
    cout << arr.dequeue() << endl;
    cout << arr.dequeue() << endl;
    cout << arr.dequeue() << endl;
    cout << arr.dequeue() << endl;

}