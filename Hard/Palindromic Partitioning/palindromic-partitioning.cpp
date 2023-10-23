//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int palindromicPartition(string str)
    {
        // code here
         int n = str.size();
        
        // Create a 2D vector to store palindrome checks for substrings.
        vector<vector<int>> check(n, vector<int>(n, 0));
        
        // Fill the 'check' matrix for palindrome checks.
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 0; j < n; j++) 
            {
                if (i > j) continue;  // Skip unnecessary comparisons.
                if (i == j) check[i][j] = 1;  // Single characters are palindromes.
                else 
                {
                    if (j == i + 1) 
                    {
                        // Handle two-character substrings.
                        if (str[i] == str[j]) check[i][j] = 1;
                        continue;
                    }
                    if (str[i] == str[j]) check[i][j] = check[i + 1][j - 1];
                }
            }
        }
        
        // Create a vector to store minimum partition counts.
        vector<int> dp(n, INT_MAX);
        dp[n - 1] = 0;  // The last character itself is a palindrome, so no partition needed.
        
        // Fill the 'dp' vector to calculate the minimum partition count.
        for (int i = n - 2; i >= 0; i--) 
        {
            int a = 1 + dp[i + 1];  // Initialize 'a' with the maximum possible value.
            
            // Iterate over potential palindrome substrings.
            for (int j = i + 1; j < n - 1; j++) 
            {
                if (check[i][j]) a = min(a, 1 + dp[j + 1]);
            }
            
            if (check[i][n - 1]) a = 0;  // The entire string is a palindrome.
            dp[i] = a;  // Update the minimum partition count for the current substring.
        }
        
        return dp[0];  // Return the minimum partition count for the entire string.
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends