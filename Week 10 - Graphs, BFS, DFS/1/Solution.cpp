#include <iostream>
#include <algorithm>
#include <vector>
#include <list>


using namespace std;


struct Graph
{
    int size;
    vector<int> adj[300000];
    int maxComponent;
    int minComponent;

    Graph(int n)
    {
        size = 2*n;
        maxComponent = 0;
        minComponent = 300000;
    }

    void addEdge(int v, int w)
    {
        adj[v].push_back(w);
        adj[w].push_back(v);
    }

    void DFSCount(int v, bool* visited, vector<int> &answer)
    {
        visited[v] = true;
        answer.push_back(v);
        //cout << v << " ";

        vector<int>::iterator it;

        for (it = adj[v].begin(); it!=adj[v].end(); it++)
        {
            if (!visited[*it])
            {
                DFSCount(*it, visited,answer);
            }
        }
    }

    void componentsInGraph(int v) {
        bool* visited = new bool[size];
        vector<int> answer;
        
        for (int i = 1; i <= size; i++)
        {
            visited[i] = false;
        }

        for (int i = 1; i <= size; i++)
        {
            if (visited[i] == false)
            {
                DFSCount(i, visited, answer);

                int curSize = answer.size();

                if (curSize > maxComponent)
                    maxComponent = curSize;
                if (curSize < minComponent && curSize!=1)
                    minComponent = curSize;

                //cout << endl;

                answer.clear();
            }
        }
    }
};


int main()
{

    int n;
    cin >> n;
    
    Graph gr = Graph(n);
    int v, w;

    for (int i = 0; i < n; i++)
    {
        cin >> v >> w;
        gr.addEdge(v, w);
    }
    
    int startVertex = 1;

    gr.componentsInGraph(startVertex);

    cout << gr.minComponent << " " << gr.maxComponent;

    system("pause");
    return 0;
}
