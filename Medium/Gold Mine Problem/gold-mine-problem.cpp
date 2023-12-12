//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    // Helper function to recursively calculate the maximum gold starting from position (i, j).
    int solve(int i, int j, int m, int n, vector<vector<int>> &arr, vector<vector<int>> &dp) {
        // Base cases: Check if the current position is out of bounds.
        if (i < 0 || i >= n || j >= m)
            return 0;

        // If the result for the current position is already calculated, return it.
        if (dp[i][j] != -1)
            return dp[i][j];

        // Recursively calculate the maximum gold by considering three possible directions.
        // Upwards diagonally
        int x = arr[i][j] + solve(i - 1, j + 1, m, n, arr, dp);

        // Downwards diagonally
        int y = arr[i][j] + solve(i + 1, j + 1, m, n, arr, dp);

        // Right
        int z = arr[i][j] + solve(i, j + 1, m, n, arr, dp);

        // Maximum of the three directions
        int maxgold = max(x, max(y, z));

        // Store the result in the dp array and return.
        return dp[i][j] = maxgold;
    }

    // Function to find the maximum amount of gold that can be collected.
    int maxGold(int n, int m, vector<vector<int>> M) {
        // Initialize a 2D dp array to store intermediate results.
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        // Initialize the maximum gold variable.
        int maxi = 0;

        // Iterate through each row to start the exploration from each possible starting point.
        for (int i = 0; i < n; i++) {
            // Calculate the maximum gold starting from position (i, 0).
            int ans = solve(i, 0, m, n, M, dp);

            // Update the overall maximum.
            maxi = max(maxi, ans);
        }

        // Return the maximum amount of gold that can be collected.
        return maxi;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}
// } Driver Code Ends