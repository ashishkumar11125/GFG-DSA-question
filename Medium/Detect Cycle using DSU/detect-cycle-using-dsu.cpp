//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> parent;
    vector<int> rank;

    // Function to find the representative of the set to which x belongs.
    int find(int x) {
        if (parent[x] == x) {
            return x;
        }

        parent[x] = find(parent[x]); // Path compression to optimize future finds.
        return parent[x];
    }

    // Function to perform union of two sets x and y.
    void union1(int x, int y) {
        int x_rep = find(x);
        int y_rep = find(y);

        if (x_rep == y_rep) {
            return; // They already belong to the same set, no need to union.
        }

        // Union by rank to optimize the depth of the tree.
        if (rank[x_rep] < rank[y_rep]) {
            parent[x_rep] = y_rep;
        } else if (rank[x_rep] > rank[y_rep]) {
            parent[y_rep] = x_rep;
        } else {
            parent[y_rep] = x_rep;
            rank[x_rep]++;
        }
    }

    // Function to detect a cycle in an undirected graph using Union-Find.
    int detectCycle(int V, vector<int> adj[]) {
        parent.resize(V);
        rank.resize(V);

        // Initialization of parent and rank arrays.
        for (int i = 0; i < V; i++) {
            parent[i] = i;
            rank[i] = 0;
        }

        set<pair<int, int>> edgeSet; // Set to store visited edges.

        for (int v = 0; v < V; v++) {
            for (auto u : adj[v]) {
                // Check if the edge has been visited in both directions.
                if (edgeSet.find({u, v}) != edgeSet.end() || edgeSet.find({v, u}) != edgeSet.end()) {
                    continue; // Skip this edge if already visited.
                }

                edgeSet.insert({u, v}); // Mark the edge as visited.

                int u_rep = find(u);
                int v_rep = find(v);

                if (u_rep == v_rep) {
                    return true; // A cycle is detected.
                }

                union1(u, v); // Union the sets of vertices u and v.
            }
        }

        return false; // No cycle detected.
    }
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		int ans = obj.detectCycle(V, adj);
		cout << ans <<"\n";	}
	return 0;
}
// } Driver Code Ends