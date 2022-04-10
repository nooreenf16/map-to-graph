#include <iostream>
#include <vector>
using namespace std;

struct Edge
{
    int src, dest;
};

class Graph
{
public:
    vector<vector<int>> adjList;

    Graph(vector<Edge> const &edges, int n)
    {
        adjList.resize(n);

        for (auto &edge : edges)
        {
            adjList[edge.src].push_back(edge.dest);
        }
    }
};

void printGraph(Graph const &graph, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << i << " -> ";
        // print all neighboring vertices of a vertex `i`
        for (int v : graph.adjList[i])
        {
            cout << v << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<Edge> edges =
        {
            {0, 1}, {0, 5}, {1, 2}, {2, 3}, {4, 3}, {5, 4}};

    int n = 6;

    Graph graph(edges, n);

    printGraph(graph, n);

    return 0;
}
