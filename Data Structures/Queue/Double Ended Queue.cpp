#include <iostream>
#include <vector>
#include <string.h>
#define maxSize 10

/*
Double Ended Queue follows both Stack(LIFO) and Queue(FIFO) properties.

Two types:
Input-restricted  : Restriction on enqueue (Insertion) Operations. Insertion from one end only and deletion is allowed from both the ends.

Output-restricted : Restriction on dequeue (Deletion) Operations. Deletion from one end only and Insertion is allowed from both the ends.

Applications: 
Can be used to perform redo and undo operations.
Used in multiprocessor scheduling
*/

class Deque
{
    int front = -1, rear = -1;
    int deque[maxSize];

public:
    void enqueueFront();
    void dequeueFront();
    void enqueueRear();
    void dequeueRear();
    void display();

    int peekFront();
    int peekRear();

    bool isFull();
    bool isEmpty();
};

//helper functions
bool Deque::isFull()
{
    return ((rear + 1) % maxSize) == front;
    //or you can use: return (front == rear + 1) || (front == 0 && rear == maxSize -1);
}

bool Deque::isEmpty()
{
    return front == -1 && rear == -1;
}

int Deque::peekFront()
{
    if (front == -1 && rear == -1)
    {
        std::cout << "Empty Queue" << std::endl;
        return 0;
    }
    return deque[front];
}

int Deque::peekRear()
{
    if (front == -1 && rear == -1)
    {
        std::cout << "Empty Queue" << std::endl;
        return 0;
    }
    return deque[rear];
}
//operations on the double ended queue

void Deque::enqueueFront()
{
    int val;
    std::cout << "Enter the value to be inserted: " << std::endl;
    std::cin >> val;
    if (isFull())
    {
        std::cout << "Overflow" << std::endl;
        return;
    }
    else if (rear == -1 && front == -1)
    {
        rear = 0;
        front = 0;
        // deque[front] = val;
    }
    // to enqueue front on the first element, we have to point front towards the end of the array.
    else if (front == 0)
    {
        front = maxSize - 1;
        // deque[front] = val;
    }
    // pointing front to the previous space
    else
    {
        front--;
        // deque[front] = val;
    }
    deque[front] = val;
}

void Deque::enqueueRear()
{
    int val;
    std::cout << "Enter the value to be inserted: " << std::endl;
    std::cin >> val;

    if (isFull())
    {
        std::cout << "Overflow" << std::endl;
        return;
    }
    else if (rear == -1 && front == -1)
    {
        rear = 0;
        front = 0;
        // deque[rear] = val;
    }
    else if (rear == maxSize - 1)
    {
        rear = 0;
        // deque[rear] = val;
    }
    else
    {
        rear++;
        // deque[rear] = val;
    }
    deque[rear] = val;
}

void Deque::dequeueFront()
{
    if (isEmpty())
    {
        std::cout << "Underflow" << std::endl;
        return;
    }
    else if (front == rear)
    {
        std::cout << "This element is deleted from the queue: " << deque[front] << std::endl;
        front = -1;
        rear = -1;
    }
    else if (front == maxSize - 1)
    {
        std::cout << "This element is deleted from the queue: " << deque[front] << std::endl;
        front = 0;
    }
    else
    {
        std::cout << "This element is deleted from the queue: " << deque[front] << std::endl;
        front++;
    }
}

void Deque::dequeueRear()
{
    if (isEmpty())
    {
        std::cout << "Underflow" << std::endl;
        return;
    }
    else if (front == rear)
    {
        std::cout << "This element is deleted from the queue: " << deque[rear] << std::endl;
        front = -1;
        rear = -1;
    }
    else if (rear == 0)
    {
        std::cout << "This element is deleted from the queue: " << deque[rear] << std::endl;
        rear = maxSize - 1;
    }
    else
    {
        std::cout << "This element is deleted from the queue: " << deque[rear] << std::endl;
        rear--;
    }
}

void Deque::display()
{

    for (int i = front; i != rear; i = (i + 1) % maxSize) //printing all the elements from "front" apart from the one in the "rear" position
    {
        std::cout << deque[i] << std::endl;
    }

    std::cout << deque[rear] << std::endl;
}

int main(int argc, char const *argv[])
{
    Deque d1;
    int choice;
    std::cout << "1) Insert element at the front end of the queue" << std::endl;
    std::cout << "2) Insert element at the rear end of the queue" << std::endl;
    std::cout << "3) Delete element from the front end of the queue" << std::endl;
    std::cout << "4) Delete element from the rear end of the queue" << std::endl;
    std::cout << "5) Peek the front end of the queue" << std::endl;
    std::cout << "6) Peek the rear end of the queue" << std::endl;
    std::cout << "7) Display the Queue" << std::endl;
    std::cout << "8) Exit" << std::endl;

    do
    {
        std::cout << "Enter your Choice: " << std::endl;
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            d1.enqueueFront();
            break;
        case 2:
            d1.enqueueRear();
            break;
        case 3:
            d1.dequeueFront();
            break;
        case 4:
            d1.dequeueRear();
            break;
        case 5:
            std::cout << d1.peekFront() << std::endl;
            break;
        case 6:
            std::cout << d1.peekRear() << std::endl;
            break;
        case 7:
            d1.display();
            break;

        default:
            break;
        }
    } while (choice != 8);

    return 0;
}
