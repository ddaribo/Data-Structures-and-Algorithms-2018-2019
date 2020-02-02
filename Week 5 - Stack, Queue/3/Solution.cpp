#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct Point
{
    int x;
    int y;

    Point()
    {
        x = 0;
        y = 0;
    }

    Point(int xx, int yy)
    {
        x = xx;
        y = yy;
    }
};

struct mazePoint
{
    Point pt;
    int dist;

    mazePoint()
    {
        pt = Point(0,0);
        dist = 0;
    }

    mazePoint(Point ptt, int distance)
    {
        pt = ptt;
        dist = distance;
    }
};

bool canPass(int row,int maxRow, int col, int maxCol)
{
    return (row >= 0) && (row < maxRow) && 
        (col >= 0) && (col < maxCol);
}

int leftAndRight[] = { -1, 0, 0, 1 };
int downAndUp[] = { 0, -1, 1, 0 };

int findShortestPath(int** maze, Point start, Point end, int m, int n)
{
    if (maze[start.x][start.y] == 1 || maze[end.x][end.y] == 1)
    {
        return -1;
    }

    bool** visited = new bool*[m];
    for (int i = 0; i < m; i++)
    {
        visited[i] = new bool[n];
        for (int j = 0; j < n; j++)
        {
            visited[i][j] = false;
        }
    }

    visited[start.x][start.y] = true;

    queue<mazePoint> path;

    mazePoint p = mazePoint(start,0);
    path.push(p);

    while (!path.empty())
    {
        mazePoint curr = path.front();
        Point pt = Point(curr.pt.x,curr.pt.y);

        if (pt.x == end.x && pt.y == end.y)
        {
            return curr.dist;
        }

        path.pop();

        for (int i = 0; i < 4; i++)
        {
            int row = pt.x + leftAndRight[i];
            int col = pt.y + downAndUp[i];

            if (canPass(row, m, col,n) && maze[row][col] == 0
                && visited[row][col]==false)
            {
                visited[row][col] = true;
                mazePoint adjacentCell = mazePoint(Point(row,col),curr.dist+1);
                
                path.push(adjacentCell);
            }
        }
    }
    return -1;
}

int main() {
    int m; cin >> m; int n; cin >> n; int k; cin >> k;

    int** maze = new int*[m];
    int curr = 0;;

    for (int i = 0; i < m; i++)
    {
        maze[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            cin >> curr;
            maze[i][j] = curr;
        }
    }

    int xK, yK;
    int* distances = new int[k];
    int i = 0;
    int q = k;
    while (k > 0)
    {
        cin >> xK;
        cin >> yK;

        int shortestDistance = findShortestPath(maze, Point(0, 0), Point(xK, yK), m, n);
        distances[i++] = shortestDistance;
        k--;
    }
    
    for (int i = 0; i < q; i++)
    {
        cout << distances[i] << endl;
    }

    for (int i = 0; i < m; i++)
    {
        delete[] maze[i];
    }
    delete[] maze;

    return 0;
}