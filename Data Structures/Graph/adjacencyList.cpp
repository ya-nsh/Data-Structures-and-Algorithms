#include <iostream>
#include <vector>
#include <string.h>
#include <bits/stdc++.h>
#define MAX 10

class Listgraph;

class Graphnode
{
    int vertex;
    Graphnode *next;

public:
    Graphnode(int n = 0)
    {
        vertex = n;
        next = NULL;
    }

    friend class Listgraph;
};

class Listgraph
{
    Graphnode *list[MAX];
    int n;
    int visited[MAX];

public:
    Listgraph(int nov)
    {
        n = nov;
        for (int i = 0; i < n; i++)
        {
            list[i] = NULL;
        }
    }

    void create();
    void display();
};

void Listgraph::create()
{
    int i, j;
    Graphnode *temp, *newnode;
    char ans;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cout << "Is there any edge b/w vertex " << i + 1 << " and " << j + 1 << std::endl;
            std::cin >> ans;

            if (ans == 'y')
            {
                newnode = new Graphnode(j + 1);

                if (list[i] == NULL)
                {
                    list[i] = temp = newnode;
                }
                else
                {
                    temp->next = newnode;
                    temp = newnode;
                }
            }
        }
    }
}

void Listgraph::display()
{
    Graphnode *temp;
    int i;
    for (int i = 0; i < n; i++)
    {
        std::cout << "\n\n"
                  << std::endl;
        std::cout << "Vertex " << i + 1 << "-->";
        temp = list[i];

        while (temp != NULL)
        {
            std::cout << "v" << temp->vertex << "-->";
            temp = temp->next;
        }
        std::cout << "NULL" << std::endl;
    }
}

int main(int argc, char const *argv[])
{
    Listgraph l1(7);
    l1.create();
    l1.display();

    return 0;
}
