//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to find the level of node X.
    int nodeLevel(int V, vector<int> adj[], int X)
    {
        // Create a queue to perform BFS (Breadth-First Search).
        queue<pair<int, int>> q;
        
        // Initialize the queue with the starting node (node 0) and level 0.
        q.push({0, 0});
        
        // Create a vector to keep track of visited nodes and initialize it with 0.
        vector<int> vis(V, 0);
        vis[0] = 1; // Mark the starting node as visited.

        // Perform BFS
        while (!q.empty())
        {
            int node = q.front().first;  // Get the current node from the front of the queue.
            int level = q.front().second; // Get the level of the current node.
            q.pop(); // Remove the current node from the queue.

            // If the current node is the target node X, return its level.
            if (node == X)
            {
                return level;
            }

            // Iterate through the adjacent nodes of the current node.
            for (auto it : adj[node])
            {
                // If the adjacent node has not been visited, mark it as visited and
                // push it into the queue with an increased level (level+1).
                if (!vis[it])
                {
                    vis[it] = 1; // Mark the adjacent node as visited.
                    q.push({it, level + 1}); // Push the adjacent node and its level into the queue.
                }
            }
        }

        // If the target node X is not found, return -1 to indicate that it's not in the graph.
        return -1;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E, X;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
    	cin>>X;

    	Solution obj;
    	cout << obj.nodeLevel(V, adj, X) << "\n";
    }

    return 0;
}


// } Driver Code Ends