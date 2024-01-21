//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
        int solve(int i, int mask, vector<pair<int,int>>& edges, int n, vector<vector<int>>& dp){
            if(i >= n) return 0;
            // if there is no one of the edge which is in cover 
            if(dp[i][mask] != -1) return dp[i][mask];
            int fe = edges[i].first, se = edges[i].second;
            int mini = 1e8;
            if((mask & (1 << (fe - 1))) && (mask & (1 << (se - 1)))){
                // I can make 1st one
                mini = min(mini, 1 + solve(i+1, mask ^ (1 << (fe - 1)), edges, n, dp));
                // I can make 2nd one
                mini = min(mini, 1 + solve(i+1, mask ^ (1 << (se - 1)), edges, n, dp));
                // I can make both these
                mini = min(mini, 2 + solve(i+1, mask ^ (1 << (fe - 1)) ^ (1 << (se - 1)), edges, n, dp));
            }else if((mask & (1 << (fe - 1))) && (!(mask & (1 << (se - 1))))){
                mini = min(mini, solve(i+1, mask, edges, n, dp));
                mini = min(mini, 1 + solve(i+1, mask ^ (1 << (fe - 1)), edges, n, dp));
            }else if((!(mask & (1 << (fe - 1)))) && (mask & (1 << (se - 1)))){
                mini = min(mini, solve(i+1, mask, edges, n, dp));
                mini = min(mini, 1 + solve(i+1, mask ^ (1 << (se - 1)), edges, n, dp));
            }else{
                mini = min(mini, solve(i+1, mask, edges, n, dp));
            }
            return dp[i][mask] = mini;
        }
        int vertexCover(int n, vector<pair<int, int>> &edges) {
            int m = edges.size();
            vector<vector<int>> dp(m, vector<int>(1 << n, -1));
            return solve(0, (1 << n) - 1, edges, m, dp);
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<pair<int,int>> edges;
        for(int i=0;i<m;i++)
        {
            int a,b;
            cin>>a>>b;
            edges.push_back({a,b});
        }
        Solution s;
        cout<<s.vertexCover(n,edges)<<endl;
    }
    return 0;
}
// } Driver Code Ends