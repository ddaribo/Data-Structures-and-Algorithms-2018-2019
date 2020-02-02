#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <set>

using namespace std;

int main() {

    int n;
    cin >> n;

    string name = "";
    string prefix = "";

    map<string, int> namesAndCount;
    set<string> nicknames;

    for (int i = 0; i < n; i++)
    {
        cin >> name;

        if (namesAndCount.count(name) == 0)
        {
            namesAndCount[name] = 1;
        }
        else
        {
            namesAndCount[name]++;
        }
        
        for (int j = 1; j <= name.length(); j++)
        {
            prefix = name.substr(0, j);

            if (nicknames.count(prefix) == 0)
            {
                nicknames.insert(prefix);

                for (int k = j; k <= name.length(); k++)
                {
                    string nameLeft = name.substr(0, k);
                    nicknames.insert(nameLeft);
                }

                break;
            }
        }
        
        if (namesAndCount[prefix] == 0 || namesAndCount[prefix] == 1)
        {
            cout << prefix << endl;
        }
        else if (namesAndCount[prefix] > 1)
        {
            cout << prefix << " " << namesAndCount[prefix] << endl;
        }
    }

    system("pause");
    return 0;
}