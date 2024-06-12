//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// Function returns the second
	// largest elements
	int print2largest(int arr[], int n) {
	    // code here
	     int l = arr[0] , sec_lar = -1 , min  = arr[0] ;
   
    for(int i = 0 ; i < n ; i++)  // finding largest element
    {
        if(arr[i] > l)
        {
            l = arr[i];
        }
    }
    
    for(int i = 0 ; i < n ; i++)  // finding second largest element
     {
        if(arr[i] < l && sec_lar < arr[i])
        {
            sec_lar = arr[i];
        }
     }
    
     return sec_lar;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.print2largest(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends