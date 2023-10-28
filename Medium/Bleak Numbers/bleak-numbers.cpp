//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
	int is_bleak(int n)
	{
	    // Code here.
	    int k = log2(n) + 1;  // Calculate the value of 'k' as the binary logarithm of 'n' plus 1.

        if (n == 1)
        {
        return 1;  // If 'n' is equal to 1, return 1 as a special case.
        }

        for (int i = 1; i <= k; i++) {
        int p = n - i, r = 0;  // Initialize 'p' as 'n - i' and 'r' as 0.
    
        while (p) 
        {
           r++;  // Count the number of set bits in 'p' by iterating through the bits.
           p = p & (p - 1);  // Clear the least significant set bit in 'p'.
        }
    
        if (r == i) 
        {
        return 0;  // If the count of set bits in 'p' is equal to 'i', return 0.
        }
    }

     return 1;  // If no 'i' is found such that the count of set bits in 'p' equals 'i', return 1.
}
    
};


//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	Solution ob;
    	int ans = ob.is_bleak(n);
    	cout << ans << "\n";
    }
	return 0;
}

// } Driver Code Ends