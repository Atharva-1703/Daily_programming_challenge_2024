#include <bits/stdc++.h>
using namespace std;

int shortestPath(int v, vector<vector<int>> edges, int s, int d)
{
    vector<vector<int>> adj(v);
    for (int i = 0; i < edges.size(); i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    vector<int> dist(v, INT_MAX);
    dist[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto it : adj[node])
        {
            if (dist[node] + 1 < dist[it])
            {
                dist[it] = dist[node] + 1;
                q.push(it);
            }
        }
    }

    return dist[d];
}

int main()
{
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 3}, {2, 3}, {3, 4}};
    cout << shortestPath(5, edges, 0, 4);
    return 0;
}