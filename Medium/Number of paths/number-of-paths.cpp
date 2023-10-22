//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
class Solution
{
    public:
    long long calculateInverse(long long a,long long b,long long m)
    {
        long long result=1;
        while(b>0)
        {
            if((b&1)==1)
            {
                result=(result*1ll*a)%m;
            }
            a=(a*1ll*a)%m;
            b=b/2;
        }
        return result;
    }
    long long  numberOfPaths(long long M, long long N)
    {
        //Code Here
        long long mod=1e9+7;
      
   long long m=M%mod;
    long long n=N%mod;
    long long  c=((n+m)%mod-2)%mod;
	long long  d=(m-1)%mod;
	long long  ans=1;
	

	for(int i=1;i<=d;i++)
	{
	   
		ans=((ans%mod)*(c%mod))%mod;

		 
		ans=((ans)*(calculateInverse(i,mod-2,mod)%mod))%mod;

		c--;
	}
	return ans%mod;
    }
};

//{ Driver Code Starts.

 
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int N, M;
		cin>>M>>N;
		Solution ob;
	    cout << ob.numberOfPaths(M, N)<<endl;
	}
    return 0;
}
// } Driver Code Ends