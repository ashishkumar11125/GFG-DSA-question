//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        long long maxArea = LLONG_MIN;
        
        vector<long long>left(n,-1);
        vector<long long>right(n,n);
        stack<long long int>st1;
        for(int i=0;i<n;i++){
            while(!st1.empty() && arr[st1.top()]>=arr[i]){
                st1.pop();
            }
            if(!st1.empty())
            left[i]=st1.top();
            st1.push(i);
        }
        stack<long long int>st2;
        
        for(int i=n-1;i>=0;i--){
            while(!st2.empty() && arr[st2.top()]>=arr[i]){
                st2.pop();
            }
            if(!st2.empty())
            right[i]=st2.top();
            st2.push(i);
        }
        
        for(int i=0;i<n;i++){
            long long int currArea = (right[i]-left[i]-1)*arr[i];
            maxArea = max(maxArea,currArea);
        }
        return maxArea;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends