#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Node
{
public:
    long long data;
    Node* left;
    Node* right;
    int size;

    Node(long long d)
    {
        data = d;
        left = nullptr;
        right = nullptr;
        size = 1;
    }


    Node* InsertInBinaryTreeAsMap(long long ai, Node* root)
    {
        if (root == nullptr)
        {
            root = new Node(ai);
            size++;
            return root;
        }
        if (ai < root->data)
        {
            root->left = InsertInBinaryTreeAsMap(ai, root->left);
        }
        if (ai > root->data)
        {
            root->right = InsertInBinaryTreeAsMap(ai, root->right);
        }
        return root;
    }
};

int main() {
    
    int n;
    cin >> n;
    long long ai;
    cin >> ai;
    Node* first = new Node(ai);

    for (int i = 0; i < n-1; i++)
    {
        long long ai;
        cin >> ai;

        first = first->InsertInBinaryTreeAsMap(ai, first);
    }

    cout << first->size;

    system("pause");
    return 0;
}