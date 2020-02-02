#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    string s = "";
    cin >> s;

    int indexMin = 0;
    int n = s.length();

    for (int i = 0; i < n - 1; i++)
    {
        indexMin = i;
        for (int j = i + 1; j < n; j++)
        {
            if (s[j]<s[indexMin])
            {
                indexMin = j;
            }
        }
        swap(s[indexMin], s[i]);
    }

    int maxOccurences = 0;
    int currentOccurences = 0;
    for (int i = 0; i < n; i++)
    {
        currentOccurences++;
        if (s[i] != s[i + 1])
        {
            if (currentOccurences > maxOccurences)
            {
                maxOccurences = currentOccurences;
            }
            currentOccurences = 0;
        }
    }

    if (maxOccurences> (n + 1) / 2)
    {
        cout << "No";
    }
    else
    {
        cout << "Yes";
    }

    system("pause");
    return 0;
}