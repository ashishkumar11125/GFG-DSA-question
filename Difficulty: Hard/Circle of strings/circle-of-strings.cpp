//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
    public:
    void dfs(int node,vector<int>adj[],vector<bool>&visited){
        visited[node]=1;
        for(int j=0;j<adj[node].size();j++){
            if(!visited[adj[node][j]]){
                dfs(adj[node][j],adj,visited);
            }
        }
    }
    
    int isCircle(int N, vector<string> A)
    {
        // code here
        //create adj list
        vector<int>adj[26];
        vector<int>indeg(26,0);
        vector<int>outdeg(26,0);
        for(int i=0;i<N;i++){
            string temp=A[i];
            int u=temp[0]-'a';
            int v=temp[temp.size()-1]-'a';
            adj[u].push_back(v);
            indeg[v]++;
            outdeg[u]++;
        }
        
        //check for elurian circuit
        for(int i=0;i<26;i++){
            if(indeg[i]!=outdeg[i])
                return 0;
        }
        
        vector<bool>visited(26,0);
        dfs(A[0][0]-'a',adj,visited);
        
        for(int i=0;i<26;i++){
            if(indeg[i] && !visited[i])
            return 0;
        }
        
        return 1;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<string> A;
        string s;
        
        for(int i = 0;i < N; i++)
        {
            cin>>s;
            A.push_back(s);
        }
        
        Solution ob;
        cout<<ob.isCircle(N, A)<<endl;
    }
    return 0;
}
// } Driver Code Ends