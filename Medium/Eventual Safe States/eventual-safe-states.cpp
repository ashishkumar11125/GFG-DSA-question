//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
  vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<int> adjRev[V];
        
        // Create an array 'indeg' to track the in-degrees of each node.
        int indeg[V] = {0};
        
        // Build the reverse adjacency list and calculate in-degrees.
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                adjRev[it].push_back(i); // Add the reverse edge.
                indeg[i]++; // Increment the in-degree of the destination node.
            }
        }
        
        // Create a queue for topological sorting.
        queue<int> q;
        
        // Create a vector 'ans' to store the eventual safe nodes.
        vector<int> ans;
        
        // Initialize the queue with nodes having in-degree 0 (no incoming edges).
        for (int i = 0; i < V; i++) {
            if (indeg[i] == 0) {
                q.push(i);
            }
        }
        
        // Perform topological sorting to identify safe nodes.
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node); // Add the node to the result.
            
            // Process all neighbors and decrement their in-degrees.
            for (auto it : adjRev[node]) {
                indeg[it]--;
                if (indeg[it] == 0) {
                    q.push(it); // If in-degree becomes 0, add it to the queue.
                }
            }
        }
        
        // Sort the result vector in ascending order.
        sort(ans.begin(), ans.end());
        
        return ans;
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

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends