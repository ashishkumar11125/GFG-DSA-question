//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Back-end complete function Template for C++

class Solution{
    bool canReach(int src, int curr, int target, vector<vector<int>>& graph, vector<int>& vis)
    {
        if(curr == target) return true;
        if(vis[curr]) return false;
        
        vis[curr] = 1;
        graph[src][curr] = 1;
        
        int ans = false;
        for(int child=0; child<graph.size(); child++)
         {
             if(graph[curr][child] == 1) {
                ans |= canReach(src,child,target,graph,vis);
             }
         }
     return ans;
    }
public:
    vector<vector<int>> transitiveClosure(int N, vector<vector<int>> graph)
    {
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<N; j++)
            {
              if(graph[i][j] == 0)
              {
                vector<int> vis(100,0);
                if(canReach(i,i,j,graph,vis)) {
                 graph[i][j] = 1;
                }
              }
            }
        }
    return graph;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> graph(N, vector<int>(N, -1));
        for(int i = 0;i < N;i++)
            for(int j=0;j<N;j++)
            cin>>graph[i][j];
        
        Solution ob;
        vector<vector<int>> ans = ob.transitiveClosure(N, graph);
        for(int i = 0;i < N;i++)
            {for(int j = 0;j < N;j++)
                cout<<ans[i][j]<<" ";
        cout<<"\n";}
    }
    return 0;
}
// } Driver Code Ends