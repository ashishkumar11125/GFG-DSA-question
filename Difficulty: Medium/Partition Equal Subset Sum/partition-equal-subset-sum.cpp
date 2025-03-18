//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool equalPartition(vector<int>& arr) {
        // code here
        int n = arr.size();
        int sum = 0;
        
        // Calculate total sum
        for(int i = 0; i < n; i++) {
            sum += arr[i];
        }
        
        // If sum is odd, equal partition is impossible
        if(sum % 2 != 0) return false;
        
        // Target sum for each subset
        int target = sum / 2;
        
        // Create DP table
        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
        
        // Empty subset can make sum 0
        for(int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }
        
        // Fill the DP table
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= target; j++) {
                // Don't include current element
                dp[i][j] = dp[i-1][j];
                
                // Include current element if possible
                if(j >= arr[i-1]) {
                    dp[i][j] = dp[i][j] || dp[i-1][j - arr[i-1]];
                }
            }
        }
        
        return dp[n][target];
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        if (ob.equalPartition(arr))
            cout << "true\n";
        else
            cout << "false\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends