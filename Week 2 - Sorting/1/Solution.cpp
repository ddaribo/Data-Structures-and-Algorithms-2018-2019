#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool comparison(string first, string second)
{
    string fres = first + second;
    string sres = second + first;
    
    if (fres.compare(sres) > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main() {

    int n;
    cin >> n;
    string nums = "";
    vector<string> numbers;

    string input = "";
    for (int i = 0; i < n; i++)
    {
        cin >> input;
        numbers.push_back(input);

    }

    int indexMax = 0;
    
    for (int i = 0; i < n - 1; i++)
    {
        indexMax = i;
        for (int j = i + 1; j < n; j++)
        {
            if (comparison(numbers[j],numbers[indexMax]))
            {
                indexMax = j;
            }
        }
        swap(numbers[indexMax], numbers[i]);
    }

    if (numbers[0] == "0")
    {
        cout << 0;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            cout << numbers[i];
        }
    }

    system("pause");
    return 0;
}

