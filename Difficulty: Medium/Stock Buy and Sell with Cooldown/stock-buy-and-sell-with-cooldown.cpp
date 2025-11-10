class Solution {
  private:
    
    int solve(int ind,int buy,vector<int>&arr,vector<vector<int>>&dp){
        if(ind>=arr.size()){
            return 0;
        }
        
        if(dp[ind][buy]!=-1){
            return dp[ind][buy];
        }
        int profit=0;
        
        if(buy){
            profit=max(-arr[ind]+solve(ind+1,0,arr,dp),solve(ind+1,1,arr,dp));
        }
        else{
            profit=max(arr[ind]+solve(ind+2,1,arr,dp),solve(ind+1,0,arr,dp));
        }
        
        return dp[ind][buy]=profit;
    }
    
    public:
    int maxProfit(vector<int>&arr) {
        // Code here
        // 1.Memoization
        // int n=arr.size();
        // vector<vector<int>>dp(n+1,vector<int>(2,-1));
        // int profit=solve(0,1,arr,dp);
        
        // return profit;
        
        //  2.tabulation
        
        // int n=arr.size();
        // vector<vector<int>>dp(n+2,vector<int>(2,0));
        // dp[n][0]=dp[n][1]=0;
        
        // for(int ind=n-1;ind>=0;ind--){
        //     for(int buy=0;buy<=1;buy++){
        //         int profit=0;
                
        //         if(buy){
        //             profit=max(-arr[ind]+dp[ind+1][0],dp[ind+1][1]);
        //         }
        //         else{
        //             profit=max(arr[ind]+dp[ind+2][1],dp[ind+1][0]);
        //         }
                
        //         dp[ind][buy]=profit;
        //     }
        // }
        
        // return dp[0][1];
        
        //3.space optimised
        vector<int>next1(2,0);
        vector<int>next2(2,0);
        vector<int>curr(2,0);
        int n=arr.size();
       
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                int profit=0;
                
                if(buy){
                    profit=max(-arr[ind]+next1[0],next1[1]);
                }
                else{
                    profit=max(arr[ind]+next2[1],next1[0]);
                }
                
                curr[buy]=profit;
            }
            next2=next1;
            next1=curr;
        }
        
        return curr[1];
    }
};