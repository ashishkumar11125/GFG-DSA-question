//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int solve(vector<int> &prices,int n,int ind,int buy,int cap
    , vector<vector<vector<int>>>&dp)
    {
        //base case
        if(ind==n || cap==0)
        {
            return 0;
        }
        
        if(dp[ind][buy][cap]!=-1)
        {
            return dp[ind][buy][cap];
        }
        
        int profit;
        
        if(buy==0)
        {
            profit= max(solve(prices,n,ind+1,0,cap,dp)
            , -prices[ind]+solve(prices,n,ind+1,1,cap,dp));
        }
        
        if(buy==1)
        {
            profit= max(solve(prices,n,ind+1,1,cap,dp)
            , prices[ind]+solve(prices,n,ind+1,0,cap-1,dp));
        }
        
        return dp[ind][buy][cap]=profit;
        
    }
  
  
    int maxProfit(vector<int> &prices) {
        // code here
        int n= prices.size();
        
        //3d dp -> dp[ind][2][3];
        
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(
            2,vector<int>(3,-1)));
            
        return solve(prices,n,0,0,2,dp);
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

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxProfit(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends