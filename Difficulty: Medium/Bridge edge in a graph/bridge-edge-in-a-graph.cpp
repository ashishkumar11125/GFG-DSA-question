//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    void dfs(int u, vector<vector<int>> &adj, vector<bool> &visited, int c, int d) {
    visited[u] = true;
    for (int v : adj[u]) {
        if ((u == c && v == d) || (u == d && v == c)) continue; // Skip the edge (c, d)
        if (!visited[v]) {
            dfs(v, adj, visited, c, d);
        }
    }
}

bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
    // Step 1: Build adjacency list
    vector<vector<int>> adj(V);
    for (auto &edge : edges) {
        int u = edge[0], v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Step 2: Run DFS from c, skipping the edge (c, d)
    vector<bool> visited(V, false);
    dfs(c, adj, visited, c, d);

    // Step 3: If d is not visited, (c, d) is a bridge
    return !visited[d];
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        vector<vector<int>> edges(E);
        int i = 0;
        while (i++ < E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            edges[i - 1].push_back(u);
            edges[i - 1].push_back(v);
        }

        int c, d;
        cin >> c >> d;

        Solution obj;
        bool l = obj.isBridge(V, edges, c, d);
        if (l)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends