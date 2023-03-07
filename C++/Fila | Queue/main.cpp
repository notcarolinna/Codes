#include <iostream>
#include "Queue.hpp"

using namespace std;

int main()
{
    Queue<int> intQueue(5); //Números

    intQueue.enqueue(10);
    intQueue.enqueue(20);
    intQueue.enqueue(30);

    cout << "Front: " << intQueue.front() << endl;
    cout << "Back: " << intQueue.back() << endl;
    cout << "Size: " << intQueue.getSize() << endl;
    
    intQueue.dequeue();

    cout << "Front: " << intQueue.front() << endl;
    cout << "Back: " << intQueue.back() << endl;
    cout << "Size: " << intQueue.getSize() << endl;
   
}
