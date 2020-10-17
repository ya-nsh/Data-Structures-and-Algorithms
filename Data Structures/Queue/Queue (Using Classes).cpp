#include <iostream>
#include <vector>
#include <string.h>
#define maxSize 10

class Queue
{

    int front = -1, rear = -1;
    int queue[maxSize];

public:
    bool isFull();
    bool isEmpty();
    int peek();
    void enqueue();
    void dequeue();
    void display();
};

// helper functions
bool Queue::isFull()
{
    return rear == maxSize - 1;
}

bool Queue::isEmpty()
{
    return front == -1 && rear == -1;
}

int Queue::peek()
{
    if (front == -1 && rear == -1)
    {
        std::cout << "Empty Queue" << std::endl;
        return 0;
    }
    return queue[front];
}

// functions for item operations to the queue
void Queue::enqueue()
{
    int val;
    //check for queue overflow
    if (isFull())
    {
        std::cout << "Overflow" << std::endl;
        exit(0);
    }
    else if (front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
    }
    else
    {
        rear++;
    }

    std::cout << "Enter the value of the data: " << std::endl;
    std::cin >> val;
    queue[rear] = val;
}

void Queue::dequeue()
{
    if (isEmpty())
    {
        std::cout << "Underflow" << std::endl;
        exit(0);
    }
    else if (front == rear) // one element in the queue condition
    {
        front = -1;
        rear = -1;
    }
    else // multiple elements in the queue condition
    {
        std::cout << "This element is deleted from the queue: " << queue[front] << std::endl;
        front++;
    }
}

void Queue::display()
{
    if (front == -1 && rear == -1)
    {
        std::cout << "Empty Queue" << std::endl;
        exit(0);
    }
    for (int i = front; i <= rear; i++)
    {
        std::cout << queue[i] << std::endl;
    }
}

// main function
int main(int argc, char const *argv[])
{
    Queue q1;
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
            q1.enqueue();
            break;
        case 2:
            std::cout << q1.peek() << std::endl;
            break;
        case 3:
            q1.dequeue();
            break;
        case 4:
            q1.display();
            break;

        default:
            break;
        }
    } while (choice != 5);

    return 0;
}
