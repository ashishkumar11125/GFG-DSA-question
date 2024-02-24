//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
        int help(int n)
    {
        if(n==0)
        return 0;
        
        int sum=help(n/2)+help(n/3)+help(n/4);
        
        if(sum>=n)
        return sum;
        else
        return n;
    }
    int maxSum(int n)
    {
        return help(n);
        }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Solution ob;
        cout<<ob.maxSum(n)<<"\n";
    }
    return 0;
}
// } Driver Code Ends