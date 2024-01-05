//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int TotalWays(int N)
	{
	    // Code here
	     long long int a=2,m=1e9+7;
        long long int b=3;
        if(N==1)
        return a*a;
        for(int i=3;i<=N;i++){
           long long int c=a+b;
            a=b;
            b=c%m;
        }
        return  (b*b)%m;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends