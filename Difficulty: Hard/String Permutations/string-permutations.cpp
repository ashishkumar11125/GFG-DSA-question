//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
   void solve(string s, vector<string>&ans,int ind){
        int n =s.length();
        //base case
        if(ind == n ){
            ans.push_back(s);
            return ;
        }
        
        for(int i=ind;i<n;i++){
            swap(s[i],s[ind]);
            solve(s,ans,ind+1);
            //backtracking
            swap(s[i],s[ind]);
        }
    }
    
    vector<string> permutation(string S)
    {
        vector<string>ans;
        solve(S,ans,0);
        sort(ans.begin(),ans.end());
        return ans;
        //Your code here
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends