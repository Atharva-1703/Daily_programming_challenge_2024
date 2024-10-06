#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *left;
    Node *right;
    int data;
    /*************  ✨ Codeium Command ⭐  *************/
    /**
     * Node constructor
     * @param data the integer data of the node
     */
    /******  0e14dc46-ef09-499e-bff1-1da8082cedf5  *******/
    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

// function to build tree
Node *buildTree(vector<int> &arr)
{
    if (arr.empty() || arr[0] == -1)
    { // edge case
        return NULL;
    }
    Node *root = new Node(arr[0]); // to create root node
    queue<Node *> q;               // queue to store nodes
    q.push(root);
    int i = 1;
    while (!q.empty() && i < arr.size())
    {
        Node *current = q.front();
        q.pop();
        if (arr[i] != -1)
        {
            current->left = new Node(arr[i]); // Assign the left child
            q.push(current->left);
        }
        i++;
        if (i < arr.size() && arr[i] != -1)
        {
            current->right = new Node(arr[i]); // Assign the right child
            q.push(current->right);
        }
        i++;
    }
    return root;
}

bool Mirror(Node *root1, Node *root2)
{
    if (!root1 || !root2)
        return root1 == root2;

    return (root1->data == root2->data) && Mirror(root1->left, root2->right) && Mirror(root1->right, root2->left);
}

bool isSymmetric(Node *root)
{
    if (!root)
        return true;

    return Mirror(root->left, root->right);
}

int main()
{
    // vector<int> arr = {1, 2, 2, -1, 3, -1, 3};
    vector<int> arr = {1, 2, 2, 3, -1, -1, 3};
    Node *root = buildTree(arr);
    cout << isSymmetric(root);
    return 0;
}