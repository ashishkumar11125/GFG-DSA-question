//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to compute the edit distance between two strings
    int editDistance(string& s1, string& s2) {
        // code here
        int m = s1.length();
        int n = s2.length();
        
        // Create DP table
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        // Initialize first row and column
        for(int i = 0; i <= m; i++) {
            dp[i][0] = i;  // Cost of deleting characters from s1
        }
        for(int j = 0; j <= n; j++) {
            dp[0][j] = j;  // Cost of inserting characters from s2
        }
        
        // Fill the DP table
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(s1[i-1] == s2[j-1]) {
                    // If characters match, no operation needed
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    // Take minimum of three operations:
                    // 1. Replace: dp[i-1][j-1] + 1
                    // 2. Delete: dp[i-1][j] + 1
                    // 3. Insert: dp[i][j-1] + 1
                    dp[i][j] = 1 + min({
                        dp[i-1][j-1],  // Replace
                        dp[i-1][j],    // Delete
                        dp[i][j-1]     // Insert
                    });
                }
            }
        }
        
        return dp[m][n];
    }
};


//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        string s1;
        getline(cin, s1);
        string s2;
        getline(cin, s2);
        Solution ob;
        int ans = ob.editDistance(s1, s2);
        cout << ans << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends