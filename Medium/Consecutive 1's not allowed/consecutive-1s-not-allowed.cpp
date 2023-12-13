//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
//User function template for C++
class Solution {
public:
    // Helper function to recursively count the number of strings ending at the given index.
    ll Helper(int index, vector<int>& dp) {
        // Base case: If the index is negative, there is one valid string.
        if (index < 0) {
            return 1;
        }

        // If the result for the current index is already calculated, return it.
        if (dp[index] != -1) {
            return dp[index];
        }

        // Recursively count the number of strings by considering two possibilities:
        // 1. Taking the current character as part of the string.
        ll take = Helper(index - 2, dp);

        // 2. Not taking the current character as part of the string.
        ll nottake = Helper(index - 1, dp);

        // Calculate the total count and store it in the dp array.
        return dp[index] = (take + nottake) % 1000000007;
    }

    // Function to count the number of valid strings of length n.
    ll countStrings(int n) {
        // Initialize a dp array to store intermediate results.
        vector<int> dp(n, -1);

        // Call the helper function to count strings ending at index (n-1).
        return Helper(n - 1, dp);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.countStrings(n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends