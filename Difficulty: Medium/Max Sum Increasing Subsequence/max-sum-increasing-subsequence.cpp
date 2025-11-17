class Solution {
  public:
    int maxSumIS(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        
        for(int last=-1;last<n;last++){
            if(last==-1 || arr[0]<arr[last]) dp[0][last+1]=arr[0];
            else dp[0][last+1]=0;
        }
        
        for(int i=1;i<n;i++){
            for(int last=-1;last<n;last++){
                int pick=0;
                if(last==-1 || arr[i]<arr[last]) pick=arr[i] + dp[i-1][i+1];
                int notpick=dp[i-1][last+1];
                dp[i][last+1]=max(pick, notpick);
            }
        }
        return dp[n-1][0];
    }
};