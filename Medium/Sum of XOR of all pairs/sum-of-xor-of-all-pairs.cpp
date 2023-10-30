//{ Driver Code Starts
// An efficient C++ program to compute 
// sum of bitwise OR of all pairs
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
public:
    // Returns the sum of bitwise OR of all pairs
    long long int sumXOR(int arr[], int n) {
        // Initialize the answer variable to store the final result
        long long int ans = 0;

        // Loop through all bits from 0 to 30 (assuming integers are 32 bits)
        for (int i = 0; i <= 30; i++) {
            // Initialize a variable to keep track of the count of 1 bits in the current bit position
            int prev = 0;

            // Loop through the array in reverse order
            for (int j = n - 1; j >= 0; j--) {
                // Check if the i-th bit of arr[j] is set (1)
                if (((arr[j] >> i) & 1)) {
                    // If the bit is set, calculate the contribution to the answer
                    // based on the count of 0 bits before the current element
                    ans += (1ll << i) * ((n - 1 - j) - prev);
                    prev++;
                } else {
                    // If the bit is not set, calculate the contribution based on the count of 1 bits before the current element
                    ans += (1ll << i) * prev;
                }
            }
        }

        // Return the final answer
        return ans;
    }
};


//{ Driver Code Starts.


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	 int n ;
	 cin>>n;
	 int arr[n+1];
	 for( int i=0;i<n;i++)
	    cin>>arr[i];
	 Solution ob;
	 cout<<ob.sumXOR(arr, n)<<endl;
	}	
	return 0;
}

// } Driver Code Ends