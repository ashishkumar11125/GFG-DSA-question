//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to find sum of all possible substrings of the given string.
    long long sumSubstrings(string s){
        
        // your code here
        int n= s.size();
        int mod= 1000000007;
        
        vector<long long> ans(n,0);
        
        for(int i=0;i<n;i++){
            
            long long num= ((i+1)*(s[i]-'0')) %mod;
            ans[i]=num;
        }
        
        
        long long res=0;
        long long temp=0;
        for(int i=0;i<n;i++){
            temp= (temp*10+ ans[i])%mod;
            res=(res+temp)%mod;
        }
        
    
        return res;
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking string
        string s;
        cin>>s;
        Solution ob;
        //calling sumSubstrings() function
        cout << ob.sumSubstrings(s) << endl;
        
    }
    return 0;
}

// } Driver Code Ends