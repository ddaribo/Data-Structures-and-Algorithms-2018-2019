#include <iostream>

#include <algorithm>

using namespace std;


void input(int arr[])
{
    for (int i = 0; i < 4; i++)
    {
        cin >> arr[i];
    }
}

int calculateDifference(int arr[])
{
    int h1 = arr[0];
    int m1 = arr[1];
    int h2 = arr[2];
    int m2 = arr[3];
    int h = 0;
    int m = 0;
    if (h2 >= h1 && m2 >= m1)
    {
        //
    }
    else if (h2>h1 && m2 < m1)
    {
        h2--;
        m2 += 60;
    }
    else if (h2 <= h1 && m2 >= m1)
    {
        h2 += 24;
    }
    else if (h2 < h1 && m2 < m1)
    {
        h2--;
        if (h2 < h1)
        {
            h2 += 24;
        }
        m2 += 60;
    }
    h = h2 - h1;
    m = m2 - m1;

    return h * 60 + m;
}

void print(int time)
{
    int h = time / 60;
    int m = time % 60;

    cout << h << ":";
    if (m < 10)
    {
        cout << "0" << m;
    }
    else
    {
        cout << m;
    }
}

int main()
{
    int time1[4];
    int time2[4];
    int time3[4];

    input(time1);
    input(time2);
    input(time3);

    int time1Span = calculateDifference(time1);
    int time2Span = calculateDifference(time2);
    int time3Span = calculateDifference(time3);

    int mini = min(time1Span, time2Span);
    if (time3Span < mini)
    {
        mini = time3Span;
    }

    int maxi = max(time1Span, time2Span);
    if (time3Span > maxi)
    {
        maxi = time3Span;
    }

    print(mini);
    cout << endl;
    print(maxi);

}