//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int grouping(string str,int ind,int sum,vector<vector<int>>& dp){
	    if(ind == str.size()) return 1;
	    int curr_sum = 0;
	    int ans = 0;
	    if(dp[ind][sum] != -1) return dp[ind][sum];
	    for(int i=ind;i<str.size();i++){
	        curr_sum += str[i] - '0';
	        if(curr_sum >= sum) 
	        ans += grouping(str,i+1,curr_sum,dp);
	    }
	    return dp[ind][sum] = ans;
	}
	int TotalCount(string str){
	    // Code here
	    int n = str.size();
	    vector<vector<int>> dp(n,vector<int>(9*n,-1));
	    return grouping(str,0,0,dp);
	}
	

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution ob;
		int ans = ob.TotalCount(str);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends