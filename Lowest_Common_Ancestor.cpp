#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *left;
    Node *right;
    int data;
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

int lowestCommonAncestor(Node *root, int x, int y)
{
    if (root == NULL)
    { // base case
        return -1;
    }
    if (root->data == x || root->data == y)
    { // base case
        return root->data;
    }
    int left = lowestCommonAncestor(root->left, x, y);
    int right = lowestCommonAncestor(root->right, x, y);
    if (left == -1)
    {
        return right;
    }
    else if (right == -1)
    {
        return left;
    }
    else
    {
        return root->data;
    }
}
int main()
{
    vector<int> arr = {3, 5, 1, 6, 2, 0, 8, -1, -1, 7, 4};
    Node *root = buildTree(arr);
    int p = 5;
    int q = 1;
    int ans = lowestCommonAncestor(root, p, q);
    cout << "LCA is: " << ans;
    return 0;
}