//{ Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

// } Driver Code Ends

class Solution{
public:
    // Function to count the number of ways to color 'n' houses using 'k' colors
    long long countWays(int n, int k){
        // Initialize variables to keep track of the number of ways for the current and previous houses.
        long long diff = k, same = 0, total = k, mod = 1e9 + 7;

        // Iterate through the houses starting from the second one.
        for(int i = 1; i < n; i++)
        {
            // Store the current 'diff' value in 'same' as it will be used for the next iteration.
            same = diff;

            // Calculate the new 'diff' value using the total number of ways and available color choices.
            diff = (total * (k - 1)) % mod;

            // Update the total number of ways by adding the current 'same' and 'diff'.
            total = (same + diff) % mod;
        }

        // Return the total number of ways to color the houses.
        return total;
    }
};



//{ Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}
// } Driver Code Ends