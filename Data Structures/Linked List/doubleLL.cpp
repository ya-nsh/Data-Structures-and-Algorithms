#include <iostream>
#include <vector>
#include <string.h>

int size = 0;


class Node
{
public:
    int data;
    Node *prev, *next;
    Node()
    {
        data = 0;
        prev = next = NULL;
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
    int val, num;
    std::cout << "Enter the number of nodes: " << std::endl;
    std::cin >> num;

    std::cout << "\n";
    for (int i = 0; i < num; i++)
    {
        Node *new_node = new Node;
        std::cout << "Enter the value ==>  ";
        std::cin >> val;

        new_node->data = val;
        new_node->next = NULL;
        new_node->prev = NULL;

        if (listptr == NULL) //empty list
        {
            //storing the address of new_node in listptr and temp;
            listptr = new_node;
            temp = new_node;
        }
        else
        {
            //attaching new_node to temp
            temp->next = new_node;
            new_node->prev = temp;

            //moving temp to the last node
            temp = new_node;
        }
        size++;
    }
}

void List::display()
{
    temp = listptr;

    std::cout << "\n\n\n"
              << std::endl;

    if (temp == NULL)
    {
        std::cout << "List is empty" << std::endl;
        return;
    }
    std::cout << "\n\n NULL-->";
    while (temp != NULL)
    {
        std::cout << temp->data << "-->";

        //moving temp to the next node
        temp = temp->next;
    }
    std::cout << "NULL" << std::endl;
    std::cout << "\n\n"
              << std::endl;
}

void List::insert_beginning()
{
    // new node will serve as the new head
    int user;
    std::cout << "Enter the value ==>  ";
    std::cin >> user;

    Node *first = new Node;

    first->data = user;
    first->next = listptr;

    listptr->prev = first;

    // adjusting the headpointer
    listptr = first;

    size++;
}

void List::insert_end()
{
    int user;

    std::cout << "Enter the value ==>  ";
    std::cin >> user;

    Node *last = new Node;
    last->data = user;

    temp = listptr;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = last;
    last->prev = temp;

    // No need of setting last->next = NULL as the constructor handles it.

    size++;
}

void List::insert_middle()
{
    int user, pos;

    std::cout << "Enter the value: " << std::endl;
    std::cin >> user;

    Node *mid = new Node;

    mid->data = user;

    std::cout << "Enter the position to insert:  " << std::endl;

    std::cin >> pos;

    if (pos < 1 || pos > size + 1)
    {
        std::cout << "Invalid Entry. " << std::endl;
        return;
    }

    temp = listptr;

    for (int i = 0; i < pos - 1; i++)
    {
        temp = temp->next;
    }

    mid->next = temp->next;
    temp->next = mid;
    mid->prev = temp;
    mid->next->prev = mid;

    size++;
}

void List::delete_beginning()
{
    temp = listptr;
    if (temp == NULL)
    {
        std::cout << "List is empty\n\n"
                  << std::endl;
        return;
    }

    listptr = temp->next;

    // Free memory
    delete temp;
    size--;
}

void List::delete_end()
{
    Node *temp2;
    temp = listptr;

    if (temp == NULL)
    {
        std::cout << "List is empty\n\n"
                  << std::endl;
        return;
    }

    // Making temp traverse till second last element
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    temp2 = temp->next;
    temp->next = NULL;

    // Free memory
    delete temp2;

    size--;
}

void List::delete_middle()
{
    // Node *temp2;
    int pos;
    temp = listptr;

    if (temp == NULL)
    {
        std::cout << "List is empty\n\n"
                  << std::endl;
        return;
    }

    std::cout << "Enter the position of the node : " << std::endl;
    std::cin >> pos;

    for (int i = 0; i < pos - 1; i++)
    {
        temp = temp->next;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    delete temp;

    // The below is using another pointer but try minimizing number of pointers for conserving space.
    // temp2 = temp->next;
    // temp->next = temp2->next;
    // temp->next->prev = temp;

    // Free memory
    // delete temp2;

    size--;
}

void List::reverse()
{
    temp = listptr;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    std::cout << "NULL-->";
    while (temp->prev != NULL)
    {
        std::cout << temp->data << "-->";

        //moving temp to the next node
        temp = temp->prev;
    }
    std::cout << temp->data << "-->NULL";
}

void List::concatenate(List l2)
{

    if (listptr == NULL || l2.listptr == NULL)
    {
        std::cout << "Empty List" << std::endl;
        return;
    }

    temp = listptr;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = l2.listptr;
    l2.listptr->prev = temp;
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
        std::cout << "10. Concatenate" << std::endl;
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

            break;

        case 10:
            l2.create();
            l1.concatenate(l2);
            l1.display();
            break;

        case 11:
            std::cout << size << std::endl;
            break;

        default:
            std::cout << "Invalid Option." << std::endl;
        }
    } while (choice != 0);

    return 0;
}
