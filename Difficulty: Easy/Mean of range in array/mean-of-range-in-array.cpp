class Solution {
  public:
    vector<int> findMean(vector<int> &arr, vector<vector<int>> &queries) {
        // code here
         int n = arr.size();
        
        vector<int> prefix(n, 0);
        prefix[0] = arr[0];
        
        for (int i=1; i<n; i++) {
            prefix[i] = (prefix[i-1] + arr[i]);
        }
        
        /* 
        [1 3 6 10 15]
         0 1 2 3  4
        */
        
        vector<int> ans;
        
        // for (int i=0; i<n; i++) {
        //     cout << prefix[i] << " ";
        // }
        for (auto& q : queries) {
            int l = q[0];
            int r = q[1];
            
            int sum = prefix[r] - ((l > 0) ? prefix[l-1] : 0);
            
            ans.push_back(sum / (r - l +1));
        }
        
        return ans;
    }
};