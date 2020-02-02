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
        // this->height = height;
    }
};

class AVLTree
{
private:
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
        if (current == NULL)
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

    void printRecursive(Node *current)
    {
        if (current == NULL)
        {
            return;
        }

        printRecursive(current->left);
        cout << current->value << " ";
        printRecursive(current->right);
    }

public:
    AVLTree()
    {
        root = NULL;
    }

    int balanceFactor(Node* node)
    {
        if (root == nullptr) return 0;

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


        return leftHeight - rightHeight;
    }

       Node* rightRotate(Node* node)
    {
          Node* movedChild = nullptr;
        if(node->left)
        {
            Node* movedChild = node->left;
            node->left = movedChild->right;
            movedChild->right = node;
            node->height = getHeight(node);
            movedChild->height = getHeight(movedChild);
        }
        

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

    
    Node* insert(double ai, Node* root)
    {
        if (root == nullptr)
        {
            root = new Node(ai,nullptr,nullptr);
        }
        if (ai < root->value)
        {
            root->left= insert(ai, root->left);
        }
        if (ai > root->value)
        {
            root->right = insert(ai, root->right);
        }
        return root;
    }

    void add(double value)
    {
        if (contains(value) == true)
        {
            cout << value << " already added" << endl;
            return;
        }
        this->root = insert(value, root);
    }

    Node* findMin(Node* node)
    {
        Node* current = node;

        while (current->left != nullptr)
        {
            current = current->left;
        }
        return current;
    }

    Node* deleteNode(Node* root, double val)
    {
        if (root == nullptr)
            return nullptr;

        if (val < root->value)
        {
            root->left = deleteNode(root->left,val);
        }
        else if (val > root->value)
        {
            root->right = deleteNode(root->right,val);
        }
        else
        {
            if (!root->left && !root->right)
            {
                delete root;
                return nullptr;
            }
            if (!root->left || !root->right)
            {
                Node* del = root->left ? root->left : root->right;
                delete root;
                return del;
            }
            if (root->left && root->right)
            {
                Node* temp = findMin(root->right);
                root->value = temp->value;
                root->right = deleteNode(root->right, root->value);
            }
        }
        return root;
    }


    void remove(double value)
    {
        if (contains(value) == false)
        {
            cout << value << " not found to remove" << endl;
            return;
        }
        root = deleteNode(root,value);
    }

    bool contains(double value)
    {
        if (root == NULL)
        {
            return false;
        }

        return containsRecursive(root, value);
    }

    void print()
    {
        if (root == NULL)
        {
            return;
        }

        printRecursive(root);
        cout << endl;
    }
};

int main()
{
    AVLTree tree;
    string operation;
    double number;
    int N;

    cin >> N;
    cout << fixed;

    for (size_t i = 0; i < N; i++)
    {
        cin >> operation;
        if (operation != "print")
        {
            cin >> number;
        }

        if (operation == "add")
        {
            tree.add(number);
        }
        else if (operation == "remove")
        {
            tree.remove(number);
        }
        else if (operation == "contains")
        {
            if (tree.contains(number))
            {
                cout << "yes" << endl;
            }
            else
            {
                cout << "no" << endl;
            }
        }
        else if (operation == "print")
        {
            tree.print();
        }
    }

    system("pause");
    return 0;
}