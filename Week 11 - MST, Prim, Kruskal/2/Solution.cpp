#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

const long long NINF = -10000000000;

void topologicalSort(int v, vector<vector<pair<int, long long>>> adj, vector<bool> &visited, stack<int> &st)
{
    visited[v] = true;

    for (auto edge : adj[v])
    {
        int neighbour = edge.first;
        
        if (!visited[neighbour])
        {
            topologicalSort(neighbour, adj, visited, st);
        }
    }
    st.push(v);
}

void longestPath(vector<vector<pair<int, long long>>> adj, int s, int t, int n)
{
    stack<int> st;
    vector<long long> distances(n + 1, NINF);
    vector<bool> visited(n + 1, false);

    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == false)
        {
            topologicalSort(i, adj, visited, st);
        }
    }

    distances[s] = 0;

    while (!st.empty())
    {
        int u = st.top();
        st.pop();

        if (distances[u] != NINF)
        {
            for (auto edge : adj[u])
            {
                int neighbour = edge.first;
                long long weight = edge.second;

                if (distances[neighbour] < distances[u] + weight)
                {
                    distances[neighbour] = distances[u] + weight;
                }
            }
        }
    }

    if (distances[t] == NINF)
    {
        cout << -1;
    }
    else
    {
        cout << distances[t];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, m, s, t;
    cin >> n >> m >> s >> t;

    vector<vector<pair<int, long long>>> adj(n + 1, vector<pair<int, long long>>());

    for (int i = 0; i < m; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        long long w;
        cin >> w;

        adj[v1].push_back(make_pair(v2, w));
    }

    longestPath(adj, s, t, n);

    system("pause");
    return 0;
}
