//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    vector<int> smallestSubsegment(int a[], int n)
    {
    	// Complete the function
    	unordered_map<int,int>fmap,smap;
    int hfq=0,s=0,e=0,l=e-s+1;
    vector<int>v;
    for(int i=0;i<n;i++){
        if(fmap.find(a[i])!=fmap.end()){
            fmap[a[i]]++;
        }
        else{
            fmap[a[i]]=1;
            smap[a[i]]=i;
        }
        if(fmap[a[i]]>hfq){
            hfq=fmap[a[i]];
            s=smap[a[i]];
            e=i;
            l=e-s+1;
        }
        else if(fmap[a[i]]==hfq){
            int len=i-smap[a[i]]+1;
            if(len<l){
                l=len;
                s=smap[a[i]];
                e=i;
            }
        }
        
    }
    for(int i=s;i<=e;i++){
        v.push_back(a[i]);
    }
    return v;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,i;
	    cin>>n; int a[n];
	    for(i=0;i<n;i++)
	    cin>>a[i];
	    vector<int > v;
	    Solution ob;
	    v = ob.smallestSubsegment(a, n);
	    for(int i:v)
	        cout<< i << " ";
	    cout<<"\n";
	}
return 0;
}

// } Driver Code Ends