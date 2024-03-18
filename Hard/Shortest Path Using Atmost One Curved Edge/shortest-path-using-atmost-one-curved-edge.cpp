//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int shortestPath(int n, int m, int aa, int b, vector<vector<int>> &e) {
        // code here
        vector<vector<int>>a[n+1];
        
        for(auto j:e)
        {
            a[j[0]].push_back({j[1],j[2],j[3]});
            a[j[1]].push_back({j[0],j[2],j[3]});
        }
        
        vector<vector<int>>vis(n+1,vector<int>(2,1e9));
        vis[aa][0]=vis[aa][1]=0;
        
        priority_queue<vector<int>, vector<vector<int>>,greater<vector<int>>>p;
        
        //cost, vertex, ifCurvedUsed
        p.push({0,aa,0});
        
        int mn = 1e9;
        
        while(p.size())
        {
            int cost = p.top()[0];
            int v = p.top()[1];
            int ifCurvedUsed = p.top()[2];
            
            p.pop();
            
            if(v == b)
            mn = min(mn,cost);
            
            else if(cost>mn)break;
            
            for(auto j:a[v])
            {
                int straight_cost = cost + j[1];
                int curved_cost = cost + j[2];
                
                if(straight_cost>= mn and curved_cost>=mn) continue; 
                
                if(ifCurvedUsed)
                {
                    if(straight_cost< vis[j[0]][1] and straight_cost<mn)
                    {
                        p.push({straight_cost, j[0], ifCurvedUsed});
                        vis[j[0]][1] = straight_cost;
                    }
                }
                else
                {
                    if(straight_cost< vis[j[0]][0] and straight_cost<mn)
                    {
                        p.push({straight_cost, j[0], ifCurvedUsed});
                        vis[j[0]][0] = straight_cost;
                    }
                    if(curved_cost< vis[j[0]][1] and curved_cost<mn)
                    {
                        p.push({curved_cost, j[0], 1});
                        vis[j[0]][1] = curved_cost;
                    }
                
                }
            }
        }
        
       int res = min(vis[b][0],vis[b][1]);
       
       return res==1e9?-1:res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,a,b;
        cin>>n>>m;
        cin>>a>>b;
        
        vector<vector<int>> edges;
        
        for(int i=0; i<m; i++)
        {
            int u,v,x,y;
            cin>>u>>v>>x>>y;
            edges.push_back({u,v,x,y});
        }

        Solution ob;
        cout << ob.shortestPath(n,m,a,b,edges) << endl;
    }
    return 0;
}
// } Driver Code Ends