#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node *buildTree(vector<int> &arr)
{
    if (arr.empty() || arr[0] == INT_MIN)
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
        if (arr[i] != INT_MIN)
        {
            current->left = new Node(arr[i]); // Assign the left child
            q.push(current->left);
        }
        i++;
        if (i < arr.size() && arr[i] != INT_MIN)
        {
            current->right = new Node(arr[i]); // Assign the right child
            q.push(current->right);
        }
        i++;
    }
    return root;
}

bool isBST(Node *root)
{
    if (root == nullptr)
    {
        return true;
    }
    if ((root->left && root->left->data > root->data) || (root->right && root->right->data < root->data))
        return false;
    return isBST(root->left) && isBST(root->right);
}

int main()
{
    vector<int> arr = {5, 1, 4, INT_MIN, INT_MIN, 3, 6};
    Node *root = buildTree(arr);
    cout << isBST(root);
    return 0;
}