#include <iostream>
#include <stack>
#include <queue>
using namespace std;

#define MAXV 1000 //maximum number of vertices

class Node
{
public:
    int key;
    Node *next;
    Node(int);
};

Node::Node(int key)
{
    this->key = key;
    this->next = NULL;
}

class EdgeNode
{
public:
    int key;
    int weight;
    EdgeNode *next;
    EdgeNode(int);
    EdgeNode(int, int);
};

EdgeNode::EdgeNode(int key)
{ // one parameter constructor
    this->key = key;
    this->weight = 0;
    this->next = NULL;
}

EdgeNode::EdgeNode(int key, int weight)
{ // two parameter constructor
    this->key = key;
    this->weight = weight;
    this->next = NULL;
}

class Graph
{

    EdgeNode *edges[MAXV + 1];
    int degree[MAXV + 1];
    int nedges;
    bool directed;

    //data members for graph traversal
    bool processed[MAXV + 1];  //which vertices have been processed
    bool discovered[MAXV + 1]; //which vertices have been found
    int parent[MAXV + 1];      //discovery relation

    //function members for graph traversal
    void initialize_search();
    void process_vertex_early(int);
    void process_vertex_late(int);
    void process_edge(int, int);

public:
    Graph(bool);
    ~Graph();
    void insert_edge(int, int, bool);
    void print_graph();
    void breadth_first_search(int);
    void depth_first_search(int);
    void find_path(int, int);
};

Graph::Graph(bool directed)
{

    this->nedges = 0;
    this->directed = directed;

    for (int i = 0; i <= MAXV; i++)
    {
        this->edges[i] = NULL;
        this->degree[i] = 0;
    }
}

Graph::~Graph()
{
    for (int i = 0; i <= MAXV; i++)
    {
        EdgeNode *e = this->edges[i];
        while (e != NULL)
        {
            EdgeNode *temp = e;
            e = e->next;
            delete temp;
            temp = NULL;
        }
    }
}

void Graph::insert_edge(int x, int y, bool directed)
{

    //create new edge
    EdgeNode *edge = new EdgeNode(y);
    //insert new edge as the head of the list
    edge->next = this->edges[x];
    this->edges[x] = edge;
    this->degree[x]++;

    if (!directed)
    {
        insert_edge(y, x, true);
    }
    else
    {
        this->nedges++;
    }
}

void Graph::print_graph()
{
    //interate through vertices
    for (int v; v <= MAXV; v++)
    {
        if (this->degree[v] > 0)
        {
            //interate through edges of the vertex
            cout << "Vertex " << v << endl;
            EdgeNode *e = this->edges[v];
            while (e != NULL)
            {
                cout << e->key << endl;
                e = e->next;
            }
        }
    }
}

void Graph::process_vertex_early(int v)
{
    cout << "Processed vertex " << v << endl;
}

void Graph::process_vertex_late(int v)
{
}

void Graph::process_edge(int x, int y)
{
    cout << "Processed edge (" << x << "," << y << ")" << endl;
}

void Graph::initialize_search()
{
    for (int i = 0; i <= MAXV; i++)
    {
        this->processed[i] = false;
        this->discovered[i] = false;
        this->parent[i] = -1;
    }
}

void Graph::breadth_first_search(int start_vertex)
{

    initialize_search();
    queue<int> q;  //queue of vertices still left to visit
    int current_v; //current vertex
    EdgeNode *p;   //temporary pointer

    q.push(start_vertex);
    this->discovered[start_vertex] = true;

    while (!q.empty())
    {
        current_v = q.front();
        q.pop();
        process_vertex_early(current_v);
        p = this->edges[current_v];
        while (p != NULL)
        {
            int neighbor_v = p->key;
            if (!this->discovered[neighbor_v])
            {
                //add to Q and set to discovered
                q.push(neighbor_v);
                this->discovered[neighbor_v] = true;
                this->parent[neighbor_v] = current_v;
            }
            if (!this->processed[neighbor_v] || this->directed)
            {
                process_edge(current_v, neighbor_v);
            }
            p = p->next;
        }
        this->processed[current_v] = true;
    }
    initialize_search();
}

//DFS is similar to BFS with the difference being the order in which vertices are explored
//main difference is that DFS uses a stack instead of a queue
//DFS is done recursively to make use of the implicit stack from recursion
//as opposed to an iterative DFS with an explicit stack
void Graph::depth_first_search(int start_vertex)
{

    int current_v = start_vertex;
    this->discovered[current_v] = true;
    EdgeNode *p = this->edges[current_v];
    process_vertex_early(current_v);

    while (p != NULL)
    {
        int neighbor_v = p->key;
        if (!this->discovered[neighbor_v])
        {
            //this->discovered[neighbor_v] = true;
            this->parent[neighbor_v] = current_v;
            process_edge(current_v, neighbor_v);
            depth_first_search(neighbor_v);
        }
        //2nd case is needed because 1st case isn't enough to visit all edges (because 1st case sets all neighbors
        //to discovered which excludes some visits to edges later)
        else if (((!this->processed[neighbor_v]) && (this->parent[current_v] != neighbor_v)) || (this->directed))
        {
            process_edge(current_v, neighbor_v);
        }
        p = p->next;
    }
    this->processed[current_v] = true;
}

int main()
{
    Graph *g = new Graph(false);
    int vertex, numberOfEdges, i, head, end;
    cout << "Enter number of nodes: ";
    cin >> vertex;
    numberOfEdges = vertex * (vertex - 1);
    for (int i = 0; i < numberOfEdges; i++)
    {
        cout << "Enter edge ex.1 2 (-1 -1 to exit): \n";
        cin >> head >> end;
        if ((head == -1) && (end == -1))
        {
            break;
        }
        g->insert_edge(head, end, false);
    }
    g->print_graph();
    cout << "BFS \n";
    g->breadth_first_search(1);
    cout << endl
         << "DFS \n";
    g->depth_first_search(1);
    cout << endl;
    delete g;
    return 0;
}
