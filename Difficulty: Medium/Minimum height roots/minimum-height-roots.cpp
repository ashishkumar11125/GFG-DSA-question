class Solution {
  public:
    vector<int> minHeightRoot(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>>list(V);
        vector<int>degree(V,0);
        vector<bool>visited(V,0);
        queue<int>q;
        int count = V;
        int size = 0;
        
        for(int i=0;i<edges.size();i++){
            list[edges[i][0]].push_back(edges[i][1]);
            list[edges[i][1]].push_back(edges[i][0]);
            degree[edges[i][0]]++;
            degree[edges[i][1]]++;
        }
        
        for(int i=0;i<V;i++){
            if(degree[i]==1)q.push(i);
        }
        
        size=q.size();
        
        while(!q.empty() && count>2){
            
            while(size--){
                
                int node = q.front();
                q.pop();
                
                visited[node]=1;
                count--;
                
                for(int i=0;i<list[node].size();i++){
                    
                    if(!visited[list[node][i]]){
                        degree[list[node][i]]--;
                        if(degree[list[node][i]]==1)q.push(list[node][i]);
                    }
                }
                
            }
            
            size=q.size();
        }
        
        
        vector<int>ans;
        for(int i=0;i<V;i++){
            if(visited[i]==0)ans.push_back(i);
        }
        
        return ans;
    }
};