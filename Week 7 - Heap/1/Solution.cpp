#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;

    Node(int d)
    {
        data = d;
        left = nullptr;
        right = nullptr;
    }


    Node* insertBinaryTree(int ai, Node* root)
    {
        if (root == nullptr)
        {
            root = new Node(ai);
            return root;
        }
        if (ai < root->data)
        {
            root->left= insertBinaryTree(ai, root->left);
        }
        if (ai >= root->data)
        {
            root->right = insertBinaryTree(ai, root->right);
        }
        return root;
    }
};

void levelOrderAverage(Node * root) {
    if (root == nullptr)
    {
        return;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty())
    {
        long temp = 0;
        int length = q.size();
        
        for (int i = 0; i < length; i++)
        {
            Node* cur = q.front();
            q.pop();
            if (cur->left)
            {
                q.push(cur->left);
            }
            if (cur->right)
            {
                q.push(cur->right);
            }
            temp += cur->data;
        }
        double avg = (double)temp / length;
        printf("%.2f\n", avg);
    }
}

int main() {
    int n;
    cin >> n;
    Node* root=nullptr;
    for (int i = 0; i < n; i++)
    {
        int ai;
        cin >> ai;
        root = root->insertBinaryTree(ai, root);
    }

    levelOrderAverage(root);

    return 0;
}
