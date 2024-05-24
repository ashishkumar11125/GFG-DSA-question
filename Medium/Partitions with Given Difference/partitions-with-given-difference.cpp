//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    int MOD = 1e9+7; 
    int solveUsingMem ( vector<int> & arr , int index , int totalSum
                        ,int currSum , int d , vector<vector<int> >& dp ) {
         if(index >= arr.size()){
           return (2*currSum - totalSum == d);
        }
        
        if(dp[index][currSum] != -1 ) {
            return dp[index][currSum] ; 
        }
        
        int exclude = solveUsingMem(arr , index + 1 ,totalSum, currSum , d  , dp) ;  
        int include = solveUsingMem(arr , index + 1 ,totalSum , currSum + arr[index] , d , dp ) ; 
        dp[index][currSum] = (exclude + include) % MOD; 
        return dp[index][currSum]  ; 
    }
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        int totalSum = 0 ; 
        for (int i = 0 ; i <  n ; i++ ) totalSum += arr[i] ; 
        
        if(totalSum - d < 0 || (totalSum+d) % 2 ){
            // we cant build ans 
            return 0;
        }
       
        int currSum = 0  ; 
        int index = 0 ; 
        vector<vector<int> > dp (n , vector<int> (totalSum+1 , -1)) ; 
        return solveUsingMem(arr  , index, totalSum , currSum , d , dp );
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends