#include <iostream>
#include <list>

using namespace std;

const int MAX = 10;

void DFS(list<int> graph[], int visited[], int node)
{
    visited[node] = 1;
    cout << node << " ";

    for(int neighbour : graph[node])
    {
        if(visited[neighbour] == 0)
        {
            DFS(graph, visited, neighbour);
        }
    }
}

void DFS_FullTraversal(list<int> graph[], int n)
{
    int visited[MAX] = {0};

    for(int i = 0; i < n; i++)
    {
        if(visited[i] == 0)
        {
            DFS(graph, visited, i);
        }
    }
}

int main()
{
    int n = 6;

    list<int> graph[MAX];

    graph[0].push_back(1);

    graph[1].push_back(0);
    graph[1].push_back(2);

    graph[2].push_back(1);

    graph[3].push_back(4);
    graph[4].push_back(3);

    cout << "Full DFS Traversal (All Components): ";

    DFS_FullTraversal(graph, n);

    cout << endl;

    return 0;
}