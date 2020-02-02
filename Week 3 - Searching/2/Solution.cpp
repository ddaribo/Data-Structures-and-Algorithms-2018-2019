#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool comparator(long i, long j)
{
    return i < j;
}

int findFirstIndex(long arr[], long x, int start, int end, int n)
{
    if (start > end)
    {
        return -1;
    }

    int middle = (start + end) / 2;
    if (arr[middle] == x && (middle == 1 || arr[middle - 1] < x)) {
        return middle;
    }
    else if (arr[middle] < x)
    {
        return findFirstIndex(arr, x, middle + 1, end, n);
    }
    else {
        return findFirstIndex(arr, x, start, middle - 1, n);
    }
}

int findLastIndex(long arr[], long x, int start, int end, int n)
{
    if (start > end)
    {
        return -1;
    }

    int middle = (start + end) / 2;
    if (arr[middle] == x && (middle == n - 1 || arr[middle + 1] > x)) {
        return middle;
    }
    else if (arr[middle] > x)
    {
        return findLastIndex(arr, x, start, middle - 1, n);
    }
    else {
        return findLastIndex(arr, x, middle + 1, end, n);
    }
}

int main() {

    int n;
    cin >> n;
    long* arr = new long[n + 1];
    arr[0] = 0;
    for (int i = 1; i < n + 1; i++)
    {
        long num;
        cin >> num;
        arr[i] = num;
    }

    sort(arr + 1, arr + n + 1, comparator);

    int queries;
    cin >> queries;

    while (queries > 0)
    {
        long elementToFind;
        cin >> elementToFind;
        int result[2];
        result[0] = findFirstIndex(arr, elementToFind, 1, n + 1, n + 1);
        result[1] = findLastIndex(arr, elementToFind, 1, n + 1, n + 1);

        for (int i = 0; i < 2; i++)
        {
            cout << result[i] << " ";
        }
        cout << endl;
        queries--;
    }
    delete[] arr;

    return 0;
}