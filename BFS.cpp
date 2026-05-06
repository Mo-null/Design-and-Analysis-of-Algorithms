#include <iostream>
#include <list>

using namespace std;

const int MAX = 10;

void BFS(list<int> graph[], int visited[], int start)
{
    int queue[MAX];

    int front = 0;
    int rear = 0;

    visited[start] = 1;

    queue[rear] = start;
    rear++;

    while(front < rear)
    {
        int current = queue[front];
        front++;

        cout << current << " ";

        for(int neighbour : graph[current])
        {
            if(visited[neighbour] == 0)
            {
                visited[neighbour] = 1;

                queue[rear] = neighbour;
                rear++;
            }
        }
    }
}

void BFS_FullTraversal(list<int> graph[], int n)
{
    int visited[MAX] = {0};

    for(int i = 0; i < n; i++)
    {
        if(visited[i] == 0)
        {
            BFS(graph, visited, i);
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

    cout << "Full BFS Traversal: ";

    BFS_FullTraversal(graph, n);

    return 0;
}