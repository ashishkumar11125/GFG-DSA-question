//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++


class Solution{
public:
    int dp[1001][1001];
    
    int solve(int l, int r, string &s){
        if(l > r)   return 0;
        else if(l == r) return 1;
        if(dp[l][r] != -1)  return dp[l][r];
        
        if(s[l] == s[r])    return dp[l][r] = (2 + solve(l+1, r-1, s));
        else    return dp[l][r] = max(solve(l+1, r, s), solve(l, r-1, s));
    }
    
    int kPalindrome(string str, int n, int k)
    {
        memset(dp, -1, sizeof(dp));
        return ((n - solve(0, n-1, str)) <= k);
    }
};




//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.kPalindrome(str, n, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends