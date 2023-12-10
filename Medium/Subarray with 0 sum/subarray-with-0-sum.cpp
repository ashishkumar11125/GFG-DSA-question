//{ Driver Code Starts
// A C++ program to find if there is a zero sum
// subarray
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution{
public:
    // Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(int arr[], int n) {
        // Your code here

        // Create a map to store the prefix sum and its frequency.
        map<int, int> mp;

        int sum = 0;

        for (int i = 0; i < n; i++) {
            // Calculate the prefix sum.
            sum += arr[i];

            // Increment the frequency of the current prefix sum in the map.
            mp[sum]++;

            // If the current prefix sum has been encountered before or if the sum is zero,
            // then there is a subarray with 0-sum.
            if (mp[sum] > 1 || sum == 0)
                return true;
        }

        // If no subarray with 0-sum is found.
        return false;
    }
};


//{ Driver Code Starts.
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    Solution obj;
	    	if (obj.subArrayExists(arr, n))
		cout << "Yes\n";
	else
		cout << "No\n";
	}
	return 0;
}
// } Driver Code Ends