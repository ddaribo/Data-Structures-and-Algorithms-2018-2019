/*
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/

    map <int, pair<int, int>> m; 
    map <int, pair<int, int>> ::iterator mapIterator;

    void findTopNodes(Node * root, int dist, int level)
    {
        if (root == NULL)
            return;

        mapIterator = m.find(dist);

        if (mapIterator == m.end())
        {
            m[dist] = make_pair(level, root->data);
        }

        else
        {
            if (mapIterator->second.first > level)
            {
                m[dist] = make_pair(level, root->data);
            }
        }
        if (root->left != NULL)
        {
            findTopNodes(root->left, dist - 1, level + 1);
        }
        if (root->right != NULL)
        {
            findTopNodes(root->right, dist + 1, level + 1);
        }

    }

    void print()
    {
        for (mapIterator = m.begin(); mapIterator != m.end(); ++mapIterator)
            cout << mapIterator->second.second << " ";
    }

    void topView(Node * root)
    {
        findTopNodes(root, 0, 0);
        print();
        return;
    }