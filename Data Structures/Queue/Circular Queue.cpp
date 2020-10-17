#include <iostream>
#include <vector>
#include <string.h>
#define maxSize 10

class Cqueue
{
    int front = -1, rear = -1;
    int cqueue[maxSize];

public:
    bool isFull();
    bool isEmpty();
    int peek();

    void enqueue();
    void dequeue();
    void display();
};

//helper functions
bool Cqueue::isFull()
{
    return ((rear + 1) % maxSize) == front;
}

bool Cqueue::isEmpty()
{
    return front = -1 && rear == -1;
}

int Cqueue::peek()
{
    if (front == -1 && rear == -1)
    {
        std::cout << "Empty Queue" << std::endl;
        return 0;
    }
    return cqueue[front];
}
// operations on the cqueue

void Cqueue::enqueue()
{
    int val;
    if (isFull())
    {
        std::cout << "Overflow" << std::endl;
        return;
    }
    else if (front == -1 && rear == -1) //no elements present inside the circular queue
    {
        front = 0;
        rear = 0;
    }
    else
    {
        rear = (rear + 1) % maxSize; //since this is a circular queue.
    }

    std::cout << "Enter the value to be inserted: " << std::endl;
    std::cin >> val;
    cqueue[rear] = val;
}

void Cqueue::dequeue()
{
    if (isEmpty())
    {
        std::cout << "Underflow" << std::endl;
        return;
    }
    else if (front == rear)
    {
        std::cout << "This element is deleted from the queue: " << cqueue[front] << std::endl;
        front = -1;
        rear = -1;
    }
    else
    {
        std::cout << "This element is deleted from the queue: " << cqueue[front] << std::endl;
        front = (front + 1) % maxSize;
    }
}

void Cqueue::display()
{
    std::cout << "----------------------------------------------------------------" << std::endl; //decoration
    int i = front;
    if (front == -1 && rear == -1)
    {
        std::cout << "Empty Queue" << std::endl;
        exit(0);
    }

    // while (i != rear)                            //this loop is also valid.
    // {
    //     std::cout << cqueue[i] << std::endl;
    //     i = (i + 1) % maxSize;
    // }

    for (int i = front; i != rear; i = (i + 1) % maxSize) //printing all the elements from "front" apart from the one in the "rear" position
    {
        std::cout << cqueue[i] << std::endl;
    }

    std::cout << cqueue[rear] << std::endl;
}

int main(int argc, char const *argv[])
{
    Cqueue cq1;
    int choice;
    std::cout << "1) Insert element to the queue" << std::endl;
    std::cout << "2) Peek the queue" << std::endl;
    std::cout << "3) Delete element from the queue" << std::endl;
    std::cout << "4) Display all the elements of the queue" << std::endl;
    std::cout << "5) Exit" << std::endl;

    do
    {
        std::cout << "Enter your Choice: " << std::endl;
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            cq1.enqueue();
            break;
        case 2:
            std::cout << cq1.peek() << std::endl;
            break;
        case 3:
            cq1.dequeue();
            break;
        case 4:
            cq1.display();
            break;

        default:
            break;
        }
    } while (choice != 5);

    return 0;
}
