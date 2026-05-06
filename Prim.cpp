#include <iostream>
#include <list>
#include <queue>
#include <vector>

using namespace std;

const int V = 5;

void primMST(list<pair<int, int>> graph[])
{
    priority_queue<
        pair<int, pair<int, int>>,
        vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>
    > pq;

    int visited[V] = {0};

    pq.push({0, {0, -1}});

    int totalCost = 0;

    cout << "Edges in MST (Node - Node \tWeight):" << endl;

    while(!pq.empty())
    {
        int weight = pq.top().first;
        int u = pq.top().second.first;
        int parent = pq.top().second.second;

        pq.pop();

        if(visited[u] == 1)
        {
            continue;
        }

        visited[u] = 1;
        totalCost += weight;

        if (parent != -1)
        {
            cout << parent << " - " << u << " \t\t" << weight << endl;
        }

        for(auto neighbour : graph[u])
        {
            int v = neighbour.first;
            int edgeWeight = neighbour.second;

            if(visited[v] == 0)
            {
                pq.push({edgeWeight, {v, u}});
            }
        }
    }

    cout << "Total Cost of MST: " << totalCost << endl;
}

int main()
{
    list<pair<int, int>> graph[V];

    graph[0].push_back({1, 2});
    graph[1].push_back({0, 2});

    graph[0].push_back({3, 6});
    graph[3].push_back({0, 6});

    graph[1].push_back({2, 3});
    graph[2].push_back({1, 3});

    graph[1].push_back({3, 8});
    graph[3].push_back({1, 8});

    graph[1].push_back({4, 5});
    graph[4].push_back({1, 5});

    graph[2].push_back({4, 7});
    graph[4].push_back({2, 7});

    graph[3].push_back({4, 9});
    graph[4].push_back({3, 9});

    primMST(graph);

    return 0;
}