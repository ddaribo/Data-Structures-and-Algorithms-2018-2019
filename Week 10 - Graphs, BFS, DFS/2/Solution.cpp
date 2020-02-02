#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>

using namespace std;

void bfs(int n, int m, int** edges, int s) {

    bool* visited = new bool[n];

    int* distances = new int[n+1];

    for (int i = 1; i <= n; i++)
    {
        distances[i] = -1;
    }

    for (int i = 1; i <= n; i++)
    {
        visited[i] = false;
    }

    visited[s] = true;

    queue<int> q;
    q.push(s);

    distances[s] = 0;

    int cur = 0;

    while (!q.empty())
    {
        cur = q.front();
        q.pop();

        for (int i = 1; i <= n; i++)
        {
            if (!visited[i] && edges[cur][i])
            {
                visited[i] = true;
                distances[i] = distances[cur] + 6;
                q.push(i);
            }
            
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (i != s)
        {
            cout << distances[i] << " ";
        }
    }
    cout << endl;

    delete[] distances;
}

int main()
{
    int q;
    cin >> q;

    int nodes;
    int edgesNum;

    int v;
    int w;

    int startNode;

    while (q > 0)
    {
        cin >> nodes >> edgesNum;

        int** edges = new int*[nodes+1];

        for (int i = 0; i <= nodes; i++)
        {
            edges[i] = new int[nodes+1];

            for ( int j = 0; j <= nodes; j++)
            {
                edges[i][j] = 0;
            }
        }

        for (int i = 0; i < edgesNum; i++)
        {
            cin >> v >> w;
            edges[v][w] = true;
            edges[w][v] = true;
        }

        cin >> startNode;

        bfs(nodes, edgesNum, edges, startNode);
    
        for (int i = 0; i < nodes; i++)
        {
            delete[] edges[i];
            
        }
        delete[] edges;

        q--;
    }

    system("pause");
    return 0;
}