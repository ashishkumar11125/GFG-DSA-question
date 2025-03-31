//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        vector<int> result;           // To store the DFS traversal
        vector<bool> visited(adj.size(), false);  // To track visited vertices
        
        // Start DFS from vertex 0
        dfsHelper(0, adj, visited, result);
        return result;
    }
    
  private:
    void dfsHelper(int vertex, vector<vector<int>>& adj, 
                  vector<bool>& visited, vector<int>& result) {
        // Mark current vertex as visited and add to result
        visited[vertex] = true;
        result.push_back(vertex);
        
        // Visit all neighbors in the order they appear in adjacency list
        for(int neighbor : adj[vertex]) {
            if(!visited[neighbor]) {
                dfsHelper(neighbor, adj, visited, result);
            }
        }
        
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        int V;
        cin >> V;
        cin.ignore();
        vector<vector<int>> adj(
            V); // Use vector of vectors instead of array of vectors.

        for (int i = 0; i < V; i++) {
            string input;
            getline(cin, input);
            int num;
            vector<int> node;
            stringstream ss(input);
            while (ss >> num) {
                node.push_back(num);
            }
            adj[i] = node;
        }

        Solution obj;
        vector<int> ans = obj.dfs(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends