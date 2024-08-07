//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        // your code here
        vector<int>ans ; 
        
        multiset<int>st ; 
        
        for (  int i = 0 ;  i < n ; i++ ) 
        {
              st.insert( arr[i] ) ; 
              
              if ( i >= k ) 
              {
                  st.erase( st.find( arr[ i - k ] ) ) ;  
              }

              if ( i >= k-1 ) 
              {   
                  int currentMaxi = *st.rbegin() ; 
                  
                  ans.push_back( currentMaxi ) ; 
              }              
              
        }
        
        return ans ; 
    }
};

//{ Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends