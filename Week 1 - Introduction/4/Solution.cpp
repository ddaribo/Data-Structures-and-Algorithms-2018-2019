#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


struct Sock {
    int first;
    int second;

    Sock(int f, int s)
    {
        first = f;
        second = s;
    }


    void print(Sock sock)
    {
        cout << sock.first << " " << sock.second;
    }

    int shorterSock()
    {
        return min(this->first, this->second);
    }

    bool operator() (Sock one, Sock two) 
    {
        bool res = false;
        if ((int)fabs(one.first - one.second) < (int)fabs(two.first - two.second))
        {
            res = true;
        }
        else if ((int)fabs(one.first - one.second) == (int)fabs(two.first - two.second))
        {
            if (one.shorterSock() < two.shorterSock())
            {
                res = true;
            }
        }
        return res;
    }

};

void input(int* arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}


int main()
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    int* socks = new int[n];

    input(socks, n);
    vector<Sock> sockPairs;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            sockPairs.push_back(Sock(socks[i], socks[j]));
        }
    }

    sort(sockPairs.begin(), sockPairs.end(), sockPairs[0]);

    sockPairs[k - 1].print(sockPairs[k - 1]);

    delete[] socks;

    return 0;
}