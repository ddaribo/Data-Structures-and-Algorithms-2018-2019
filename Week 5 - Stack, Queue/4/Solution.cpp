#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/* This solution passes half of the test cases due to timeout - needs improvement of complexity  */

int main() {
    int n;
    cin >> n;

    vector<int> magicNumbers;

    if (n >= 1 && n <= 9)
    {
        for (int i = 1; i <=n; i++)
        {
            magicNumbers.push_back(i);
        }
    }
    else if (n >= 10)
    {
        for (int i = 1; i <= 9; i++)
        {
            magicNumbers.push_back(i);
        }
    }

    for (int i = 10; i <= n; i++)
    {
    
        int k = i;
        int count = 0;
        while (i > 0)
        {
            i /= 10;
            count++;
        }
        i = k;
        bool isMagic = true;
        while (isMagic)
        {
            int leftDigit = i % 10;
            i /= 10;
            count--;
            int rightDigit = i % 10;
            if (count<=0)
            {
                break;
            }
            else if (abs(leftDigit - rightDigit) != 2)
            {
                isMagic = false;
                break;
            }
            
        }
        i = k;
        if (isMagic)
        {
            magicNumbers.push_back(k);
        }
        
    }

    for (int i = 0; i < magicNumbers.size(); i++)
    {
        cout << magicNumbers[i] << " ";
    }

    return 0;
}