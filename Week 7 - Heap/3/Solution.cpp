#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> adjacencyList[100001];
bool visited[100001];
int starbucks[100001];
int numberOfPaths = 0;

void findNumberOfPossiblePaths(int currNode, int maxCaffes, int* nodes)
{
    for (int i = 0; i < adjacencyList[currNode].size(); i++)
    {
        if (visited[adjacencyList[currNode][i]] == false)
        {
            visited[adjacencyList[currNode][i]] = true;
            starbucks[adjacencyList[currNode][i]] = (starbucks[currNode] + 1) * nodes[adjacencyList[currNode][i]];

            if (starbucks[adjacencyList[currNode][i]] > maxCaffes)
            {
                continue;
            }
            findNumberOfPossiblePaths(adjacencyList[currNode][i], maxCaffes, nodes);
        }
    }
    if (adjacencyList[currNode].size() == 1 && currNode != 1 && starbucks[currNode] <= maxCaffes)
    {
        numberOfPaths++;
    }
}


int main()
{
    int n;
    cin >> n;
    int maxConsequentCaffes;
    cin >> maxConsequentCaffes;

    int nodes[100001];

    for (int i = 1; i <= n; i++)
    {
        int ai;
        cin >> ai;
        nodes[i] = ai;
    }

    
    for (int i = 0; i < n - 1; i++)
    {
        int e1;
        cin >> e1;
        int e2;
        cin >> e2;

        adjacencyList[e1].push_back(e2);
        adjacencyList[e2].push_back(e1);
    }

    visited[1] = true;
    starbucks[1] = nodes[1];

    findNumberOfPossiblePaths(1,maxConsequentCaffes,nodes);

    cout << numberOfPaths;

    system("pause");
    return 0;
}