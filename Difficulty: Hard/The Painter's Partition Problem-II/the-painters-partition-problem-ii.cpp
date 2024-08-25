//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    bool count(int arr[], long long mid, int n,int k) {
        long long count=1,sum=0;
        for(int i=0;i<n;i++) {
            if(arr[i]>mid) return false;
            if(sum+arr[i]>mid) {
                count++;
                sum=arr[i];
                if(count>k) return false;
            }
            else sum += arr[i];
        }
        return true;
    }
    long long minTime(int arr[], int n, int k)
    {
        // code here
        // return minimum 
        
        long long ans=-1;
        long long start = *max_element(arr,arr+n);
        long long end=0;
       for(int i = 0 ; i< n ; i++){
           end+=arr[i];
       }
        while(start<=end){
            long long  mid = start+(end-start)/2;
            if(count(arr,mid,n,k)){
                ans = mid;
                end = mid-1;
            }else{
                start = mid+1;
            }
        }
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
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}
// } Driver Code Ends