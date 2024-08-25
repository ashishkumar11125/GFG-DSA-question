//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxProfit(int k, int n, int arr[]) {
        // code here
        
        //0=>first buy
        //1=>first sell
        //2=>second buy
        //3=>second sell
        //4=>third buy
        //5=>third sell and so one upto k
        
        //total 2*k indices
        //odd ones describes sell, and even ones describes buy
        
        vector<vector<pair<int,bool>>>dp(n,vector<pair<int,bool>>(2*k, {0,false}));
        
        dp[0][0]= make_pair(-arr[0],true);
        for (int i=1; i<n; i++){
            
            dp[i][0]= make_pair(max(-arr[i],dp[i-1][0].first),true);
            for (int j=1; j<2*k; j++){
                if (!dp[i-1][j-1].second) break;
                
                if (j%2==0){
                    dp[i][j]= make_pair(dp[i-1][j-1].first-arr[i],true);
                    
                    if (dp[i-1][j].second)
                        dp[i][j].first= max(dp[i][j].first,dp[i-1][j].first);
                } else {
                    dp[i][j]= make_pair(dp[i-1][j-1].first+arr[i],true);
                    
                    if (dp[i-1][j].second)
                        dp[i][j].first= max(dp[i][j].first,dp[i-1][j].first);
                }
            }
        }
        
        
        int profit= 0;
        for (int i=0; i<n; i++)
            for (int j=0; j<2*k; j++)
                profit= max(profit,dp[i][j].first);
            
        
        return profit;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}
// } Driver Code Ends