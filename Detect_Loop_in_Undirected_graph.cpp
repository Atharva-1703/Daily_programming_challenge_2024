#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, int parent, vector<int> vis, vector<vector<int>> adj)
{
    vis[node] = 1;
    for (auto adjacentNode : adj[node])
    {
        if (!vis[adjacentNode])
        {
            if (dfs(adjacentNode, node, vis, adj) == true)
                return true;
        }
        else if (adjacentNode != parent)
            return true;
    }
    return false;
}

bool detectLoop(int v, int e, vector<vector<int>> edges)
{
    vector<vector<int>> adj(v);
    for (int i = 0; i < e; i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    vector<int> vis(v, 0);
    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            if (dfs(i, -1, vis, adj) == true)
                return true;
        }
    }
    return false;
};

int main()
{
    vector<vector<int>> edges = {{0, 1}, {1, 2}};
    cout << detectLoop(3, 2, edges);
    return 0;
}