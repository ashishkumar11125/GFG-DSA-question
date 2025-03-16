//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int minJumps(vector<int>& arr) {
        // code here
         // code here
        if(arr[0] == 0)
        return -1;
        int n = arr.size();
        vector<int> dp(n,INT_MAX);
        dp[0] = 0;
        for(int i = 1;i<n;i++)
        {
            for(int j = i-1;j>=0;j--)
            {
                if(arr[j] + j >= i && dp[j] != INT_MAX)
                {
                    dp[i] = min(dp[i], 1+dp[j]);
                }
            }
        }
        int ans = dp[n-1];
        if(ans == INT_MAX)
        return -1;
        
        return ans;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, i, j;
        vector<int> arr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.minJumps(arr) << endl << "~\n";
    }
    return 0;
}

// } Driver Code Ends