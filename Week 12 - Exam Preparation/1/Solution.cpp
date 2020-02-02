#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t > 0)
    {
        int n;
        cin >> n;

        if (n <= 0)
        {
            cout << 0 << endl;
            t--;
            continue;
        }

        int* arr = new int[n];

        for (int i = 0; i < n; i++)
        {
            int ai;
            cin >> ai;
            arr[i] = ai;
        }

        if (n == 1)
        {
            cout << arr[0] << endl;
            t--;
            continue;
        }

        sort(arr, arr + n);

        int sum = 0;

        if (n % 2 == 0)
        {
            int i = 0;
            
            while (arr[i] <= 0)
            {
                if (arr[i + 1] <= 0)
                {
                    sum += max(arr[i] * arr[i + 1], arr[i] + arr[i + 1]);
                }
                else
                {
                    break;
                }

                i += 2;
                if (i >= n - 1) break;
            }

            for (int j = i; j < n; j += 2)
            {
                sum += max(arr[j] * arr[j + 1], arr[j] + arr[j + 1]);
            }
        }
        else
        {
            int i = 0;
            while (arr[i] <= 0)
            {
                if (arr[i + 1] <= 0)
                {
                    sum += max(arr[i] * arr[i + 1], arr[i] + arr[i + 1]);
                }
                else
                {
                    break;
                }

                i += 2;
                if (i >= n - 1) break;
            }

            sum += arr[i];

            for (int j = i + 1; j < n; j += 2)
            {
                sum += max(arr[j] * arr[j + 1], arr[j] + arr[j + 1]);
            }
        }

        cout << sum << endl;

        delete[] arr;
        t--;
    }

    system("pause");
    return 0;
}