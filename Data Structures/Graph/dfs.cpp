#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

// Initializing variables
int counter, i, j, numVertices, stk[10], top, v, visited[15], visit[15];
int cost[10][10];

int main()
{
    int numEdges;

    // User Inputs
    cout << "Enter the number no of vertices: ";
    cin >> numVertices;
    cout << "Enter the no of edges: ";
    cin >> numEdges;
    cout << "\nEDGES \n";
    for (counter = 1; counter <= numEdges; counter++)
    {
        cin >> i >> j;
        cost[i][j] = 1;
    }

    // Initial Vertex to traverse from
    cout << "Enter initial vertex to traverse from: ";
    cin >> v;

    // DFS Logic
    cout << "DFS ORDER OF VISITED VERTICES: ";
    cout << v << " ";

    visited[v] = 1;
    counter = 1;

    while (counter < numVertices)
    {
        for (j = numVertices; j >= 1; j--)
            if (cost[v][j] != 0 && visited[j] != 1 && visit[j] != 1)
            {
                visit[j] = 1;
                stk[top] = j;
                top++;
            }

        v = stk[--top];

        cout << v << " ";

        counter++;

        visit[v] = 0;
        visited[v] = 1;
    }
    return 0;
}