#include <cstdio>
#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* next;

    Node()
    {
        data = 0;
        next = nullptr;
    }
};

class LinkedListImpl
{
private:
    Node* head;
    Node* tail;
public:
    long long sum;
    int max;
    int min;

    LinkedListImpl()
    {
        head = nullptr;
        tail = nullptr;
        sum = 0;
        min = 0;
        max = 0;
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
            max = data;
            min = data;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
        if (data > max)
        {
            max = data;
        }
        else if (data < min)
        {
            min = data;
        }
        sum += data;
    }

};



int main() {

    ios_base::sync_with_stdio(false);

    LinkedListImpl input;
    int num;
    
    //ctrl+Z for end of input
    while (cin >> num)
    {
        input.insertAtEnd(num);
    }

    long long sum = input.sum;
    int min = input.min;
    int max = input.max;

    cout << min << " " << max << " " << sum;

    return 0;
}