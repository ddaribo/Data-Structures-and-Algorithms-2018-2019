#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>

using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    Node* head = new Node();
    Node* tail = new Node();

    int n;
    cin>> n;
    int result = 0;

    head->data = 1;
    head->next = nullptr;
    tail = head;

    for (int i = 2; i <= n; i++)
    {
        if (i % 2 != 0)
        {
                Node* newNode = new Node();
                newNode->data = i;
                tail->next = newNode;
                tail = newNode;
        }
    }
    tail->next = head;

    Node* left = new Node();
    Node* current = new Node();

    if (n % 2 == 0)
    {
        left = head;
        current = head;
    }
    else
    {
        left = head->next;
        current = head->next;
        head = head->next;
        tail->next = head;
    }
    while (left->next != left)
    {
        current = left;
        left = left->next;


        current->next = left->next;
        delete left;
        left = current->next;
    }

    cout << current->data;

    return 0;
}
