//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    // Function to check if the graph has an Eulerian Circuit.
    int isEulerCircuit(int V, vector<int> adj[]) {
        // Variable to count vertices with odd degrees.
        int odd = 0;

        // Iterate through each vertex in the graph.
        for (int i = 0; i < V; i++) {
            // Check if the degree of the current vertex is odd.
            if (adj[i].size() & 1) {
                odd++;
            }
        }

        // Determine the type of Eulerian Circuit based on the count of vertices with odd degrees.
        if (odd == 0) {
            // If no vertex has an odd degree, return 2 indicating a Eulerian Circuit.
            return 2;
        } else if (odd == 2) {
            // If exactly two vertices have odd degrees, return 1 indicating a Eulerian Path.
            return 1;
        } else {
            // If the count of vertices with odd degrees is neither 0 nor 2, return 0 indicating no Eulerian Circuit.
            return 0;
        }
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
		int ans = obj.isEulerCircuit(V, adj);
		cout << ans <<"\n";	}
	return 0;
}
// } Driver Code Ends