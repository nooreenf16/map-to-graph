#include <iostream>
#include <set>
#include <list>
#include <algorithm>
#include <vector>
//#include "location.cpp"
using namespace std;

void location(int min_node)
{
    vector<int> database;
    database.push_back(min_node);
}
typedef struct nodes
{
    int dest;
    int cost;
    int arr[5];
} node;

class Graph
{
    int n;
    list<node> *adjList;

public:
    void showList(int src, list<node> lt)
    {
        list<node>::iterator i;
        node tempNode;

        for (i = lt.begin(); i != lt.end(); i++)
        {
            tempNode = *i;
            cout << "(" << src << ")---(" << tempNode.dest << "|" << tempNode.cost << ") ";
        }
        cout << endl;
    }

public:
    Graph()
    {
        n = 0;
    }

    Graph(int nodeCount)
    {
        n = nodeCount;
        adjList = new list<node>[n];
    }

    void addEdge(int source, int dest, int cost, int arr[])
    {
        node newNode;
        newNode.dest = dest;
        newNode.cost = cost;
        *newNode.arr = *arr;
        cout << newNode.arr[0] << endl;
        adjList[source].push_back(newNode);
    }

    void displayEdges()
    {
        for (int i = 0; i < n; i++)
        {
            list<node> tempList = adjList[i];
            showList(i, tempList);
        }
    }

    friend void dijkstra(Graph g, int *dist, int *prev, int start);
};

void dijkstra(Graph g, int *dist, int *prev, int start)
{
    int n = g.n;

    for (int u = 0; u < n; u++)
    {
        dist[u] = 9999; // set as infinity
        prev[u] = -1;   // undefined previous
    }

    dist[start] = 0; // distance of start is 0
    set<int> S;      // create empty set S
    list<int> Q;

    for (int u = 0; u < n; u++)
    {
        Q.push_back(u); // add each node into queue
    }

    while (!Q.empty())
    {
        list<int>::iterator i;
        i = min_element(Q.begin(), Q.end());
        int u = *i; // the minimum element from queue
        Q.remove(u);
        S.insert(u); // add u in the set
        list<node>::iterator it;

        for (it = g.adjList[u].begin(); it != g.adjList[u].end(); it++)
        {
            if ((dist[u] + (it->cost)) < dist[it->dest])
            { // relax (u,v)
                dist[it->dest] = (dist[u] + (it->cost));
                prev[it->dest] = u;
            }
        }
    }
}

main()
{
    int vertices = 7;
    int edges = 6;
    int arr[5] = {1, 2, 3, 4, 5};
    Graph g(vertices);
    int dist[vertices], prev[vertices];
    int start = 0;
    g.addEdge(1, 7, 1, arr);
    for (int i = 0; i < edges; i++)
    {
        int n1, n2;
        cout << "enter edges: ";
        cin >> n1;
        cin >> n2;

        g.addEdge(n1, n2, 1, NULL);
    }

    /*g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 4, 1);
    g.addEdge(5, 4, 1);
    g.addEdge(6, 5, 1);*/

    dijkstra(g, dist, prev, start);
    int min_node = INT_MAX;
    for (int i = 0; i < vertices; i++)
        if (i != start)
        {
            cout << start << " to " << i << ", Distance: " << dist[i] << " Previous: " << prev[i] << endl;
            if (dist[i] < min_node)
                min_node = i;
        }

    cout << "Node chosen = " << min_node << endl;

    cout << "save?" << endl;
    char input[10];
    cin >> input;
    if (input == "save")
        location(min_node);
}