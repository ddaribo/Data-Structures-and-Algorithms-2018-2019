#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

long merge(int toys[], int left, int middle, int right)
{
    int size1 = middle - left + 1;
    int size2 = right - middle;

    int* L = new int[size1];
    int* R = new int[size2];

    for (int i = 0; i < size1; i++)
    {
        L[i] = toys[left + i];
    }
    for (int i = 0; i < size2; i++)
    {
        R[i] = toys[middle + 1 + i];
    }

    int i = 0, j = 0;
    int k = left;
long inversionsCount=0;

    while (i < size1 && j < size2)
    {
        if (L[i] <= R[j])
        {
            toys[k] = L[i];
            i++;
        }
        else
        {
            toys[k] = R[j];
            j++;
inversionsCount += size1-i;
        }
        k++;
    }

    while (i < size1)
    {
        toys[k] = L[i];
        i++; k++;
    }
    while (j < size2)
    {
        toys[k] = R[j];
        j++; k++;
    }

    delete[] L;
    delete[] R;
    
return inversionsCount;
}

long mergeSort(int toys[], int left, int right)
{
long inv=0;
    if (left < right)
    {
        int middle = (left + right) / 2;

      inv = mergeSort(toys, left, middle);
      inv+=  mergeSort(toys, middle + 1, right);

       inv+= merge(toys, left, middle, right);
    }
return inv;
}

int main()
{
    int queries;
    cin >> queries;
    vector<long> results;
    long count = 0;
    while (queries > 0)
    {
        int m;
        cin >> m;
        int* soldiers = new int[m];

        for (int i = 0; i < m; i++)
        {
            cin >> soldiers[i];
        }

         count = mergeSort(soldiers,0, m-1);

        results.push_back(count);

        delete[] soldiers;

        queries--;
    }

    for (int i = 0; i < results.size(); i++)
    {
        cout << results[i] << endl;
    }

    return 0;
}
