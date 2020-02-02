#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

struct Node
{
    double value;
    Node *left;
    Node *right;
    int height;

    Node(double value, Node *left, Node *right)
    {
        this->value = value;
        this->left = left;
        this->right = right;
    }
};

class AVLTree
{
public:
    Node *root;

    int getHeight(Node* node)
    {
        if (node == nullptr) return 0;

        int leftHeight;
        int rightHeight;

        if (node->left == nullptr)
        {
            leftHeight = 0;
        }
        else
        {
            leftHeight = 1 + node->left->height;
        }
        if (node->right == nullptr)
        {
            rightHeight = 0;
        }
        else
        {
            rightHeight = 1 + node->right->height;
        }

        if (leftHeight > rightHeight)
        {
            return leftHeight;
        }

        return rightHeight;
    }

    bool containsRecursive(Node *current, double value)
    {
        if (current == nullptr)
        {
            return false;
        }

        if (current->value == value)
        {
            return true;
        }

        if (value < current->value)
        {
            return containsRecursive(current->left, value);
        }
        else
        {
            return containsRecursive(current->right, value);
        }
    }


    AVLTree()
    {
        root =nullptr;
    }

   int balanceFactor(Node* node)
    {
        if (node == nullptr) return 0;

        int leftHeight = getHeight(node->left);
        int rightHeight = getHeight(node->right);
        
        return leftHeight - rightHeight;
    }
    
    Node* rightRotate(Node* node)
    {
        Node* movedChild = node->left;
        node->left = movedChild->right;
        movedChild->right = node;
        node->height = getHeight(node);
        movedChild->height = getHeight(movedChild);

        return movedChild;
    }

    Node* leftRotate(Node* node)
    {
        Node* movedChild = node->right;
        node->right = movedChild->left;
        movedChild->left = node;

        node->height = getHeight(node);
        movedChild->height = getHeight(movedChild);
        return movedChild;
    }


    Node* leftRightRotate(Node* node)
    {
        node->left = leftRotate(node->left);
        Node* movedChild = rightRotate(node);

        return movedChild;
    }

    Node* rightLeftRotate(Node* node)
    {
        node->right = rightRotate(node->right);
        Node* movedChild = leftRotate(node);

        return movedChild;
    }

    Node* insert(double value, Node* node)
    {
        if (node == nullptr)
        {
            node = new Node(value, nullptr, nullptr);
            return node;
        }
        else if (value > node->value)
        {
            node->right = insert(value, node->right);

            if (balanceFactor(node) == -2)
            {
                if (value > node->right->value)
                {
                    node = leftRotate(node);
                }
                else
                {
                    node = rightLeftRotate(node);
                }
            }
        }
        else
        {
            if (value < node->value)
            {
                node->left = insert(value, node->left);

                if (balanceFactor(node) == 2)
                {
                    if (value < node->left->value)
                    {
                        node = rightRotate(node);
                    }
                    else
                    {
                        node = leftRightRotate(node);
                    }
                }
            }
        }

        node->height = getHeight(node);
        return node;
    }

    void add(double value)
    {
        if (contains(value) == true)
        {
            return;
        }
        this->root = insert(value, root);
    }


    bool contains(double value)
    {
        if (root == NULL)
        {
            return false;
        }

        return containsRecursive(root, value);
    }

};

int main()
{
    AVLTree tree;

    int N;
    int pairs;
    cin >> N;
    cin >> pairs;
    int count=1;

    Node* root = new Node(N, nullptr, nullptr);
    tree.root = root;

    for (int i = 0; i < pairs; i++)
    {
        int n1;
        int n2;
        
        cin >> n1 >> n2;

        if (tree.contains(n1))
        {
            if (!tree.contains(n2))
            {
                tree.add(n2);
                count++;
            }
        }

    }
    cout << count;

    system("pause");
    return 0;
}