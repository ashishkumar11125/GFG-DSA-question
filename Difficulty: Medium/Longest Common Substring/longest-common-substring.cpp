//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestCommonSubstr(string str1, string str2) {
        // your code here
         // Get the lengths of both input strings
    int n = str1.size();
    int m = str2.size();
    
    // Create a 2D vector (DP table) to store the length of the longest common substring
    // dp[i][j] will represent the length of the longest common substring that ends at str1[i-1] and str2[j-1]
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    
    // Variable to store the maximum length of the common substring found
    int ans = 0;
    
    // Loop through all characters of str1 (from 1 to n)
    for(int i = 1; i <= n; i++) {
        // Loop through all characters of str2 (from 1 to m)
        for(int j = 1; j <= m; j++) {
            
            // If characters match (str1[i-1] == str2[j-1]), extend the common substring
            if (str1[i-1] == str2[j-1]) {
                
                // Add 1 to the previous diagonal value dp[i-1][j-1]
                dp[i][j] = 1 + dp[i-1][j-1];
                
                // Update the maximum length of the common substring found so far
                ans = max(ans, dp[i][j]);
            } else {
                // If characters don't match, reset dp[i][j] to 0
                // Since no common substring can end at these characters
                dp[i][j] = 0;
            }
        }
    }
    
    // Return the maximum length of the common substring found
    return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr(s1, s2) << endl;
    }
}
// } Driver Code Ends