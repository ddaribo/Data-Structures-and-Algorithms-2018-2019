#include <cstdio>
#include <vector>
#include <list>
#include <iostream>
using namespace std;

/* One test case not passing - Abort called */

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

struct LinkedList
{
    Node * head;
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

struct Snowman
{
    LinkedList snowBalls;
    int totalValue;

    Snowman()
    {
        totalValue = 0;
    }
};


int main() {

    int N;
    cin >> N;
    vector<Snowman> vect;
    vect.push_back(Snowman());
    vect[0].snowBalls.insertAtEnd(0);

    for (int i = 1; i <= N; i++)
    {
        vect.push_back(Snowman());
    }
    int p; int m;
    long totalSum = 0;
    for (int i = 1; i <= N; i++)
    {
        cin >> p;
        cin >> m;

        if (m == 0)
        {
            vect[i].totalValue = (vect[p].totalValue - vect[p].snowBalls.tail->data);
            Node* current = vect[p].snowBalls.head;
            while (current != vect[p].snowBalls.tail)
            {
                vect[i].snowBalls.insertAtEnd(current->data);
                current = current->next;
            }
            totalSum += vect[i].totalValue;

        }
        else
        {
            vect[i].totalValue = vect[p].totalValue + m;
            Node* current = vect[p].snowBalls.head;
            while (current != nullptr)
            {
                vect[i].snowBalls.insertAtEnd(current->data);
                current = current->next;
            }
            vect[i].snowBalls.insertAtEnd(m);
            totalSum += vect[i].totalValue;
        }
    }

    cout << totalSum;

    system("pause");
    return 0;
}