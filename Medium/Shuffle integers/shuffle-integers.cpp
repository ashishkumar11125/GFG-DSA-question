//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    void shuffleArray(int arr[], int n) {
        // Create a vector to store the interleaved elements.
        vector<int> ans;

        // Iterate through the first half of the array.
        for (int i = 0; i < n / 2; i++) {
            // Add an element from the first half.
            ans.push_back(arr[i]);
            
            // Add an element from the second half.
            ans.push_back(arr[n / 2 + i]);
        }

        // Update the input array with the interleaved elements.
        for (int i = 0; i < n; i++) {
            arr[i] = ans[i];
        }
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
	    cin>>n;
	    int a[n] ;
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	    }


       

        Solution ob;
        ob.shuffleArray(a, n);

		for (int i = 0; i < n; i++) 
			cout << a[i] << " ";
    
	
        
	    cout << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends