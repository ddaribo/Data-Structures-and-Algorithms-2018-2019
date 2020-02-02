#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void input(int* arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

bool comparatorFunctionDescending(int i, int j)
{ 
    return (i > j); 
}


int main()
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    int* goods = new int[n];

    input(goods, n);

    sort(goods, goods + n, comparatorFunctionDescending);

    int minimalSum = 0;
    int freeGoodsIndex = k - 1;

    for (int i = 0; i < n; i++)
    {
        if (i % k == freeGoodsIndex)
        {
            //
        }
        else
        {
            minimalSum += goods[i];
        }
    }

    cout << minimalSum;

    delete[] goods;
    
    return 0;
}