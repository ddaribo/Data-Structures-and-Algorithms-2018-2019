#include <cmath>
#include <cstdio>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

const long long INF = 10000000000;

void dijkstra(int s, vector<vector<pair<long, long long>>> adj, int n)
{
    vector<long long> distances;
    for (size_t i = 0; i <= n; i++)
    {
        distances.push_back(INF);
    }
    vector<bool> visited;
    for (size_t i = 0; i <= n; i++)
    {
        visited.push_back(false);
    }

    distances[s] = 0;

    for (int i = 1; i <= n; i++)
    {
        long v = -1;
        for (int j = 1; j <= n; j++)
        {
            if (!visited[j] && (v == -1 || distances[j] < distances[v]))
            {
                v = j;
            }
        }

        if (distances[v] == INF)
            break;

        visited[v] = true;

        for (auto edge: adj[v])
        {
            long to = edge.first;
            long long length = edge.second;

            if (distances[v] + length < distances[to])
            {
                distances[to] = distances[v] + length;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (i != s)
        {
            if (distances[i] == INF)
            {
                cout << -1 << " ";
            }
            else
            {
                cout << distances[i] << " ";
            }
        }
    }
    cout << endl;
}

int main() {
    int t;
    ios_base::sync_with_stdio(false);
    cin >> t;

    while (t > 0)
    {
        long n, m;
        cin >> n >> m;
        vector<vector<pair<long, long long>>> adj(n+1, vector<pair<long, long long>>());

        for (int i = 0; i < m; i++)
        {
            long u, v;
            long long w;
            cin >> u >> v >> w;

            pair<long, long long> p1 = make_pair(v, w);
            pair<long, long long> p2 = make_pair(u, w);
            adj[u].push_back(p1);
            adj[v].push_back(p2);

        }
        long s;
        cin >> s;
        dijkstra(s, adj, n);

        t--;
    }

    system("pause");
    return 0;
}

