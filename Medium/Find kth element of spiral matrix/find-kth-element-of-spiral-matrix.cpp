//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends
class Solution
{
    public:
    /*You are required to complete this method*/
    int findK(int a[MAX][MAX],int n,int m,int k)
    {
 		// Your code goes here.
 		int scol=0;
 		int ecol=m-1;
 		int srow=0;
 		int erow=n-1;
 		int count=1;
 		while(count<=k)
 		{
 		    for(int i=scol;i<=ecol;i++){
 		        if(count==k) return a[srow][i];
 		        count++;
 		    }
 		    srow++;
 		    for(int i=srow;i<=erow;i++){
 		        if(count==k) return a[i][ecol];
 		        count++;
 		    }
 		    ecol--;
 		    for(int i=ecol;i>=scol;i--){
 		        if(count==k) return a[erow][i];
 		        count++;
 		    }
 		    erow--;
 		    for(int i=erow;i>=srow;i--){
 		        if(count==k) return a[i][scol];
 		        count++;
 		    }
 		    scol++;
 		}
 		return 0;
    }
};





//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        Solution ob;
        cout<<ob.findK(a,n,m,k)<<endl;
        
       
    }
}
// } Driver Code Ends