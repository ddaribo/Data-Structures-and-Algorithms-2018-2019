#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Node
{
    int data;
    Node* next;
};

struct LinkedList
{
    Node* head;
    Node* tail;
    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    void insertAtEnd(int data)
    {
        Node* temp = new Node;
        temp->data = data;
        temp->next = nullptr;
        if (head == nullptr)
        {
            head = temp;
            tail = temp;
            temp = nullptr;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }
};

bool alreadyExists(pair<int, int> p,vector<pair<int,int>> pairs)
{
    for(int i = 0; i<pairs.size();i++)
    {
        if ((p.first == pairs[i].first && p.second == pairs[i].second)
            ||
            (p.first == pairs[i].second && p.second == pairs[i].first))
        {
            return true;
        }
    }
    return false;
}



int main()
{
    int n;
    cin >> n;
    LinkedList list=LinkedList();
    int num;
    for (int i = 0; i< n; i++)
    {
        cin >> num;
        list.insertAtEnd(num);
    }
    int p;
    cin >> p;

    int* arr = new int[p];
    for (int i = 0; i < p; i++)
    {
        cin >> num;
        arr[i]=num;
    }

    int counts[1235];
    for (int i = 1; i < 1235; i++)
    {
        
        counts[i] = 0;
    }
    for (int i = 0; i < p; i++)
    {
        if(arr[i] >=1 && arr[i]<=1234) 
        counts[arr[i]]++;
    }

    vector<pair<int, int>> allPairs;
    Node* current = new Node;

    current=list.head;
    int count = 0;

    while (current->next != nullptr)
    {
        if (counts[current->data] > 0 && counts[current->next->data] > 0)
        {
            pair<int, int> curr = make_pair(current->data, current->next->data);
            if (alreadyExists(curr,allPairs) == false)
            {
                allPairs.push_back(curr);
                count++;
            }
        }
        current = current->next;
    }

    cout << count;

    delete[] arr;
    
    return 0;
}
