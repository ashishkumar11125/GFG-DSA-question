//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sum = 0;
        for (int i=0; i<n; i++)
        {
            sum += arr[i];
        }
        vector<int> S1 =  subsetSum(arr, n, sum);
        
        int mn = INT_MAX;
        for (int i = 0; i<S1.size(); i++)
        {
            mn = min(mn, sum - 2*S1[i]);
        }
        return mn;
    } 
    
    vector<int> subsetSum(int arr[], int n, int sum)
    {
        //initialization
        bool t[n+1][sum + 1];
        for (int i = 0; i < n+1; i++)
        {
            for (int j = 0; j< sum+1; j++)
            {
                if (i==0)
                    t[i][j] = false;
                if (j==0)
                    t[i][j] = true;
            }
        }
        
        for (int i = 1; i< n+1; i++){
            for (int j = 1; j < sum+1; j++){
                if(arr[i-1] <= j)
                    t[i][j] = t[i-1][j] || t[i-1][j-arr[i-1]];
               else
                    t[i][j] = t[i-1][j];
            }
        }
        
        //return the last row first half
        vector<int> V;
        for (int j = 0; j <= sum/2; j++){
            if (t[n][j] == true)
                V.push_back(j);
        }
        return V;
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
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends