#include <iostream>
#include <list>
#include <queue>
#include <vector>

using namespace std;

const int V = 5;
const int INF = 999999;

void printPath(vector<int>& parent, int j)
{
    if (parent[j] == -1)
    {
        cout << j;
        return;
    }
    printPath(parent, parent[j]);
    cout << " -> " << j;
}

void dijkstra(list<pair<int, int>> graph[], int source)
{
    vector<int> distance(V, INF);
    vector<int> parent(V, -1);

    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;

    distance[source] = 0;
    pq.push({0, source});

    while(!pq.empty())
    {
        int dist = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (dist > distance[u]) continue;

        for(auto neighbour : graph[u])
        {
            int v = neighbour.first;
            int weight = neighbour.second;

            if(distance[u] + weight < distance[v])
            {
                distance[v] = distance[u] + weight;
                parent[v] = u;
                pq.push({distance[v], v});
            }
        }
    }

    cout << "Vertex\tDistance\tPath" << endl;
    for(int i = 0; i < V; i++)
    {
        cout << i << "\t" << distance[i] << "\t\t";
        printPath(parent, i);
        cout << endl;
    }
}

int main()
{
    list<pair<int, int>> graph[V];

    graph[0].push_back({1, 10});
    graph[0].push_back({4, 5});
    graph[1].push_back({2, 1});
    graph[1].push_back({4, 2});
    graph[2].push_back({3, 4});
    graph[3].push_back({0, 7});
    graph[3].push_back({2, 6});
    graph[4].push_back({1, 3});
    graph[4].push_back({2, 9});
    graph[4].push_back({3, 2});

    dijkstra(graph, 0);

    return 0;
}