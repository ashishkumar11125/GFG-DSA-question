//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string longestPalin (string S) {
        // code here
         int n = S.size();
        vector<vector<int>> dp(n,vector<int>(n, 0));
        string ans;
        int maxlength = 0;
        for(int diff=0; diff<n; diff++){
            for(int i=0, j=i+diff; j<n; i++, j++){
                if(i == j)
                {
                    dp[i][j] = 1;    
                }
                else if(diff == 1)
                {
                    dp[i][j] = (S[i]==S[j])?2:0;
                }
                else
                {
                    if(S[i]==S[j] and dp[i+1][j-1])
                    {
                        dp[i][j] = dp[i+1][j-1]+2;
                    }
                }
                if(dp[i][j])
                {
                    if(j-i+1 > maxlength)
                    {
                        maxlength = j-i+1;
                        ans = S.substr(i, maxlength);
                    }
                }
            }
        }   
        return ans;
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends