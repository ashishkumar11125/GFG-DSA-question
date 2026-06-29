class Solution {
  public:
    int maxDotProduct(vector<int>& a, vector<int>& b) {
        // code here
        int dp[1003][1003];
        memset(dp,-1,sizeof(dp));
        
        int as = a.size();
        int bs = b.size();
        auto f = [&](auto&& f, int i, int j)->int{
            if(i==as){
                if(j==bs){
                    return 0;
                }
                else{
                    return -1e9;
                }
            }
            if(j==bs) return 0;
            if(dp[i][j]!=-1) return dp[i][j];
            int take = a[i]*b[j] + f(f,i+1,j+1);
            int nottake = f(f,i+1,j);
            int ans = max({take, nottake});
            return dp[i][j] = ans;
        };
        
        return f(f,0,0);
    }
};
