#include <vector>
#include <iostream>
using namespace std;

void merge(int toys[], int left, int middle, int right)
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
}

void mergeSort(int toys[], int left, int right)
{
    if (left < right)
    {
        int middle = (left + right) / 2;

        mergeSort(toys, left, middle);
        mergeSort(toys, middle + 1, right);

        merge(toys, left, middle, right);
    }
}


int main() {
    int n;
    int k;
    cin >> n >> k;
    int input;
    int* toys = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> input;
        toys[i] = input;
    }
    int leftIndex = 0;
    int rightIndex = n - 1;
    mergeSort(toys, leftIndex, rightIndex);

    long sum = 0;
    int count = 0;

    for (count = 0; count < n; count++)
    {
        sum += toys[count];
        if (sum >= k) {
            break;
        }
    }

    cout << count;

    delete[] toys;

    system("pause");
    return 0;
}