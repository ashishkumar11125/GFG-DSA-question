//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:

        int LCSof3 (string a, string b, string c, int n1, int n2, int n3)
{
    // your code here
    vector<vector<vector<int>>> dp(n1 + 1,vector<vector<int>> (n2 + 1,vector<int> (n3 + 1,0))) ;
    
    for(int i = 1 ; i <= n1 ; i++)
        for(int j = 1 ; j <= n2 ; j++)
            for(int k = 1 ; k <= n3 ; k++)
            {
                if(a[i - 1] == b[j - 1] and a[i - 1] == c[k - 1])
                    dp[i][j][k] = 1 + dp[i - 1][j - 1][k - 1] ;
                else
                    dp[i][j][k] = max({dp[i - 1][j][k],dp[i][j - 1][k],dp[i][j][k - 1]}) ;
            }
    
    return dp[n1][n2][n3] ;
        }
};


//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; cin >> n1 >> n2 >> n3;
        string A, B, C; cin >> A >> B >> C;
        Solution obj;
        cout << obj.LCSof3 (A, B, C, n1, n2, n3) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends