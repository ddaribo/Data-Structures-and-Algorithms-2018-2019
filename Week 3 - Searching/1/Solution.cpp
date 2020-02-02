#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int queries;
    cin >> queries;

    int results[1001];
    int count = 0;
    while (queries > 0)
    {
        double n;
        cin >> n;
        if(n==0)
        {
            results[count++] = 0;
        }
        else{
            results[count++] = (int)log2(n) + 1;
        }

        queries--;
    }
    for (int i = 0; i < count; i++)
    {
        cout << results[i] << endl;
    }
    
    return 0;
}