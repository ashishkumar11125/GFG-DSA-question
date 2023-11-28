//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    // Function to calculate the sum of dependencies in a directed graph.
    int sumOfDependencies(vector<int> adj[], int V) {
        int result = 0;

        // Iterate through each vertex in the graph.
        for (int i = 0; i < V; i++) 
        {
            // Accumulate the size of the adjacency list for each vertex.
            result += adj[i].size();
        }

        return result;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<int> v[N];
        for (int i = 0; i < M; i++) {
            cin >> x >> y;
            v[x].push_back(y);
        }
        Solution ob;
        cout << ob.sumOfDependencies(v, N) << "\n";
    }
}
// } Driver Code Ends