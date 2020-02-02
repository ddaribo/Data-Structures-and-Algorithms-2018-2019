#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct maxHeap
{
    vector<int> v;

    int parent(int i)
    {
        return (i - 1) / 2;
    }

    int leftChild(int i)
    {
        return (2 * i + 1);
    }

    int rightChild(int i)
    {
        return (2 * i + 2);
    }

    void siftDown(int i)
    {

        int left = leftChild(i);
        int right = rightChild(i);

        int largest = i;

        if (left < size() && v[left] > v[i])
            largest = left;

        if (right < size() && v[right] > v[largest])
            largest = right;

        if (largest != i) {
            swap(v[i], v[largest]);
            siftDown(largest);
        }
    }

    void siftUp(int i)
    {
        if (i && v[parent(i)] < v[i])
        {
            swap(v[i], v[parent(i)]);

            siftUp(parent(i));
        }
    }

    unsigned int size()
    {
        return v.size();
    }

    void push(int num)
    {
        v.push_back(num);

        int index = size() - 1;
        siftUp(index);
    }

    void pop()
    {
        if (size() == 0) return;
        else
        {
            v[0] = v.back();
            v.pop_back();

            siftDown(0);
        }
    }

    int top()
    {
        if (size() == 0) return 0;
        else return v.at(0);
    }
};
struct minHeap
{

    vector<int> v;

    int parent(int i)
    {
        return (i - 1) / 2;
    }

    int leftChild(int i)
    {
        return (2 * i + 1);
    }

    int rightChild(int i)
    {
        return (2 * i + 2);
    }

    void siftDown(int i)
    {
        int left = leftChild(i);
        int right = rightChild(i);

        int smallest = i;

        if (left < size() && v[left] < v[i])
            smallest = left;

        if (right < size() && v[right] < v[smallest])
            smallest = right;

        if (smallest != i) {
            swap(v[i], v[smallest]);
            siftDown(smallest);
        }
    }

    void siftUp(int i)
    {
        if (i && v[parent(i)] > v[i])
        {
            swap(v[i], v[parent(i)]);

            siftUp(parent(i));
        }
    }

    unsigned int size()
    {
        return v.size();
    }


    void push(int num)
    {
        v.push_back(num);

        int index = size() - 1;
        siftUp(index);
    }

    void pop()
    {
        if (size() == 0) return;
        else
        {
            v[0] = v.back();
            v.pop_back();

            siftDown(0);
        }
    }

    int top()
    {
        if (size() == 0) return 0;
        else return v.at(0);
    }
};

void findAllMedians(vector<int> nums, int n)
{
    minHeap minH;
    maxHeap maxH;
    double median = 0.0;

    for (int i = 0; i < n; i++)
    {
        int ai = nums[i];

        if (ai <= median)
        {
            maxH.push(ai);
        }
        else
        {
            minH.push(ai);
        }

        if (minH.size() > maxH.size() + 1)
        {
            maxH.push(minH.top());
            minH.pop();
        }
        if (maxH.size() > minH.size() + 1)
        {
            minH.push(maxH.top());
            maxH.pop();
        }

        if (minH.size() == maxH.size())
        {
            int sum = maxH.top() + minH.top();
            median = (double)sum / 2.0;
        }
        else if (minH.size() > maxH.size())
        {
            median = (double)minH.top();
        }
        else if (maxH.size() > minH.size())
        {
            median = (double)maxH.top();
        }

        printf("%.1f\n", median);
    }
}

int main() {

    int n;
    cin >> n;
    vector<int> nums;

    for (int i = 0; i < n; i++)
    {
        int ai;
        cin >> ai;
        
        nums.push_back(ai);
    }
    
    findAllMedians(nums, n);

    system("pause");
    return 0;
}