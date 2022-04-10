#include <iostream>
#include <list>

using namespace std;

class Node
{
    int slots;
    Node *next;
};

class Graph
{
    int V; // No. of vertices
    list<int> *adj;

public:
    Graph(int V);
    void addEdge(int v, int w);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    return 0;
}