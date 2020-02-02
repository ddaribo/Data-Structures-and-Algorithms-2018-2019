#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;

bool comparator(long i, long j)
{
    return i < j;
}

bool allElementsAre0(long arr[], int length)
{
    bool result = true;
    for (int i = 0; i < length; i++)
    {
        if (arr[i] != 0)
        {
            result = false;
        }
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    long* clothes = new long[n];

    long dryer;
    cin >> dryer;

    for (int i = 0; i < n; i++)
    {
        long num;
        cin >> num;
        clothes[i] = num;
    }

    sort(clothes, clothes + n, comparator);

    int days = 0;

    while (allElementsAre0(clothes, n) == false)
    {
        clothes[n - 1] = clothes[n-1] - dryer;
        if (clothes[n - 1] < 0)
        {
            clothes[n - 1] = 0;
        }
        for (int i = 0; i < n - 1; i++)
        {
            clothes[i]--;
            if (clothes[i] < 0)
            {
                clothes[i] = 0;
            }
        }
        sort(clothes, clothes + n, comparator);
        days++;
    }
    cout << days;

    delete[] clothes;
    
    return 0;
}
