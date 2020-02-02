#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    
    string a = "";
    string b = "";

    cin >> a >> b;

    int aLength = a.length();
    int bLength = b.length();

    int minLength = min(aLength, bLength);
    int maxLength = max(aLength, bLength);

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    char lastFound = ' ';
    string result = "";
    int lastMatchIndex = -1;

    if (minLength == aLength)
    {
        for (int i = 0; i < minLength; i++)
        {
        
            for (int j = lastMatchIndex; j < maxLength; j++)
            {
                if (j == lastMatchIndex)
                {
                    continue;
                }
                if (a[i] == b[j])
                {
                    result += a[i];
                    lastFound = a[i];
                    lastMatchIndex = j;
                    break;
                }
            }
        }
    }
    else
    {
        for (int i = 0; i < minLength; i++)
        {
            for (int j = lastMatchIndex; j < maxLength; j++)
            {
                if (j == lastMatchIndex)
                {
                    continue;
                }
                if (b[i] == a[j])
                {
                    result += b[i];
                    lastFound = b[i];
                    lastMatchIndex = j;
                    break;
                }
            }
        }
    }
    

    cout << result;

    system("pause");
    return 0;
}
