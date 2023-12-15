//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    long long int mod = 1000000007; // Define a constant for modulo operation.

    int nthPoint(int n)
    {
        // Code to calculate the nth point using dynamic programming.

        // Initialize an array to store solutions for subproblems.
        int dp[n + 1];
        
        // Base cases: the number of ways to reach 0 and 1 points is 1.
        dp[0] = dp[1] = 1;

        // Iterate from 2 to n to fill the dp array.
        for (int i = 2; i <= n; i++)
            dp[i] = (dp[i - 1] + dp[i - 2]) % mod; // Calculate the number of ways to reach the current point using the previous two points.

        return dp[n]; // Return the result for the nth point.
    }
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans  = ob.nthPoint(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends