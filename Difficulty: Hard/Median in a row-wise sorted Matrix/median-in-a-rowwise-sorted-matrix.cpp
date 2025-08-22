class Solution {
  public:
    int median(vector<vector<int>> &mat) {
        // code here
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>minheap;
        vector<int>temp;
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<n;i++){
            minheap.push({mat[i][0],{i,0}});
        }
        while(!minheap.empty()){
            auto front=minheap.top();
            int value=front.first;
            int i=front.second.first;
            int j=front.second.second;
            minheap.pop();
            temp.push_back(value);
            if(j+1 < m){
                minheap.push({mat[i][j+1],{i,j+1}});
            }
        }
        return temp[temp.size()/2];
    }
};
