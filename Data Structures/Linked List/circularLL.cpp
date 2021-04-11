#include <iostream>
#include <vector>
#include <string.h>

int size = 0;

class Node
{
public:
    int data;
    Node *next;
    Node() //default constructor
    {
        data = 0;
        next = NULL;
    }
};

class List : public Node
{
    Node *listptr, *temp;

public:
    List()
    {
        listptr = NULL;
        temp = NULL;
    }

    void create();
    void display();

    void insertion();

    void insert_beginning();
    void insert_middle();
    void insert_end();

    void delete_beginning();
    void delete_middle();
    void delete_end();

    void reverse();

    void concatenate(List);
};

void List::create()
{
    int num;

    std::cout << "Enter the number of nodes : " << std::endl;
    std::cin >> num;

    for (int i = 0; i < num; i++)
    {
        Node *new_node = new Node;

        std::cout << "Enter data :  " << std::endl;
        std::cin >> new_node->data;

        if (listptr == NULL)
        {
            listptr = new_node;
            temp = new_node;

            new_node->next = listptr;
        }
        else
        {
            temp->next = new_node;
            new_node->next = listptr;

            temp = new_node;
        }
    }
}

void List::display()
{
    temp = listptr;

    if (temp == NULL)
    {
        std::cout << "List is empty" << std::endl;
        return;
    }

    do
    {
        std::cout << temp->data << "-->";
        temp = temp->next;

    } while (temp != listptr);

    std::cout << "NULL" << std::endl;
}

void List::insert_beginning()
{
    Node *new_node = new Node;
    std::cout << "Enter data : " << std::endl;
    std::cin >> new_node->data;

    new_node->next = listptr;

    temp = listptr;

    while (temp->next != listptr)
    {
        temp = temp->next;
    }

    temp->next = new_node;

    listptr = new_node;
}

void List::insert_end()
{
    Node *new_node = new Node;
    std::cout << "Enter data : " << std::endl;
    std::cin >> new_node->data;

    temp = listptr;

    while (temp->next != listptr)
    {
        temp = temp->next;
    }

    temp->next = new_node;
    new_node->next = listptr;

    // Also this one
    // new_node->next = listptr;
    // temp->next = new_node;
}

// Insertion in between is exactly same as that of linear one
void List::insert_middle()
{
    Node *new_node = new Node;

    int pos;

    std::cout << "Enter data : " << std::endl;
    std::cin >> new_node->data;

    std::cout << "Enter position: " << std::endl;
    std::cin >> pos;

    temp = listptr;

    for (int i = 0; i < pos - 1; i++)
    {
        temp = temp->next;
    }

    new_node->next = temp->next;
    temp->next = new_node;
}

void List::delete_beginning()
{
    Node *temp2, *first;
    temp2 = first = listptr;

    while (temp2->next != listptr)
    {
        temp2 = temp2->next;
    }

    listptr = listptr->next;
    temp2->next = listptr;

    delete first;
}

void List::delete_end()
{
    Node *temp2;
    temp = listptr;

    // // for 1 node in the list :
    // if (temp->next == temp)
    // {
    //     temp = NULL;
    // }

    while (temp->next->next != listptr)
    {
        temp = temp->next;
    }

    temp2 = temp->next;
    delete temp2;

    temp->next = listptr;
}

void List::delete_middle()
{
    int pos;
    Node *temp2;
    std::cout << "Enter position :" << std::endl;
    std::cin >> pos;

    temp = listptr;
    for (int i = 0; i < pos - 1; i++)
    {
        temp = temp->next;
    }
    temp2 = temp->next;

    temp->next = temp2->next;

    delete temp2;
}

void List::concatenate(List l2)
{
    Node *temp1, *temp2;

    temp1 = listptr;
    temp2 = l2.listptr;

    while (temp1->next != listptr)
    {
        temp1 = temp1->next;
    }

    temp1->next = l2.listptr;

    while (temp2->next != l2.listptr)
    {
        temp2 = temp2->next;
    }
    temp2->next = listptr;
}

void List::reverse()
{ // Traverse the whole list and adjusting the link part of each node to point to the prev. node instead of the next node.
    // Node *forward, *current, *backward;

    // current = listptr;
    // backward = NULL;

    // while (current != listptr)
    // {
    //     // Storing the forward node.
    //     forward = current->next;

    //     // Setting the link part of the current node as the address of the prev. node.
    //     current->next = backward;

    //     // Moving pointers one position ahead.
    //     backward = current;
    //     current = forward;
    // }
    // // backward stores the address of the first node of the reversed list as current and forward point to NULL.
    // listptr = backward;

    Node *prev, *cur, *next, *last;

    // Head is going to be our last node after reversing list
    last = listptr;

    prev = listptr;
    cur = listptr->next;
    listptr = listptr->next;

    // Iterate till you reach the initial node in circular list
    while (listptr != last)
    {
        listptr = listptr->next;
        cur->next = prev;

        prev = cur;
        cur = listptr;
    }

    cur->next = prev;
    listptr = prev; // Make last node as head
}

int main(int argc, char const *argv[])
{
    int choice;
    List l1, l2;
    do
    {
        std::cout << "\n\nChoose from the following: " << std::endl;
        std::cout << "-------------------------------" << std::endl;

        std::cout << "1. Create a new node." << std::endl;
        std::cout << "2. Display list" << std::endl;
        std::cout << "3. Insert Beginning" << std::endl;
        std::cout << "4. Insert End" << std::endl;
        std::cout << "5. Insert Middle" << std::endl;
        std::cout << "6. Delete beginning" << std::endl;
        std::cout << "7. Delete end" << std::endl;
        std::cout << "8. Delete middle" << std::endl;
        std::cout << "9. Reverse" << std::endl;
        std::cout << "10.  Concatenate" << std::endl;
        std::cout << "11. Size" << std::endl;
        std::cout << "0. Exit" << std::endl;

        std::cout << "\nEnter Choice : ";
        std::cin >> choice;
        switch (choice)
        {
        case 0:
            std::cout << "Exited." << std::endl;
            break;

        case 1:
            l1.create();
            l1.display();
            break;

        case 2:
            l1.display();
            break;

        case 3:
            l1.insert_beginning();
            l1.display();
            break;

        case 4:
            l1.insert_end();
            l1.display();
            break;

        case 5:
            l1.insert_middle();
            l1.display();
            break;

        case 6:
            l1.delete_beginning();
            l1.display();
            break;

        case 7:
            l1.delete_end();
            l1.display();
            break;

        case 8:
            l1.delete_middle();
            l1.display();
            break;

        case 9:
            l1.reverse();
            l1.display();
            break;

        case 10:
            l2.create();
            l1.concatenate(l2);
            l1.display();
            break;

            // case 11:
            //     std::cout << size << std::endl;
            //     break;

        default:
            std::cout << "Invalid Option." << std::endl;
        }
    } while (choice != 0);

    return 0;
}
