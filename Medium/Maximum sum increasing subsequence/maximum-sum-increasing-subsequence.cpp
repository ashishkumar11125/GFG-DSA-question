//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{

	public:
	int maxSumIS(int arr[], int n)  
	{  
	   // Your code goes here
// Initialize a dynamic programming vector 'dp' with the same values as 'arr'.
      vector<int> dp(arr, arr + n);

// Iterate over each element in 'arr' to find the maximum sum.
      for (int i = 1; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
// If 'arr[i]' is greater than 'arr[j]', update 'dp[i]' with the maximum sum.
        if (arr[i] > arr[j]) 
        {
            dp[i] = max(dp[i], arr[i] + dp[j]);
        }
    }
}


// Return the maximum value in 'dp', representing the maximum sum of increasing elements in 'arr'.
         return *max_element(dp.begin(), dp.end());
    }
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends