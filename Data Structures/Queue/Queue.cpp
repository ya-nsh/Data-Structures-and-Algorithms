#include <iostream>
#include <vector>
#include <string.h>

//Initializing global variables
int queue[50], maxSize = 100, choice, front = -1, rear = -1;

// Creating helper Functions
bool isFull()
{
    return rear == maxSize - 1;
}

bool isEmpty()
{
    return (front < 0 || front > rear);
}

int peek()
{
    return queue[front];
}

// Queue Operations
void insert()
{
    int val;
    if (rear == maxSize - 1)
    {
        std::cout << "Queue Overflow" << std::endl;
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }
        rear++;
        std::cout << "Enter the value of the data: " << std::endl;
        std::cin >> val;

        queue[rear] = val;
    }
}

void deleteElements()
{
    if (front == -1 || front > rear)
    {
        std::cout << "Queue Underflow" << std::endl;
        exit(0);
    }
    std::cout << "This element is deleted from the queue: " << queue[front] << std::endl;
    front++;
}

void display()
{
    if (front == -1 || rear == -1)
    {
        std::cout << "Empty" << std::endl;
    }
    else
    {
        std::cout << "Queue elements are: " << std::endl;
        for (int i = front; i <= rear; i++)
        {
            std::cout << queue[i] << std::endl;
        }
    }
}

int main(int argc, char const *argv[])
{
    int data;
    std::cout << "1) Insert element to the queue" << std::endl;
    std::cout << "2) Peek the queue" << std::endl;
    std::cout << "3) Delete element from the queue" << std::endl;
    std::cout << "4) Display all the elements of the queue" << std::endl;
    std::cout << "5) Exit" << std::endl;

    do
    {
        std::cout << "Enter your Choice: " << std::endl;
        std::cin >> choice;
        // system("cls");
        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            std::cout << peek() << std::endl;
        case 3:
            deleteElements();
            break;
        case 4:
            display();
            break;

        default:
            break;
        }
    } while (choice != 5);

    return 0;
}
