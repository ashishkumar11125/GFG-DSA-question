class Solution {
  public:
    vector<vector<int>> insertInterval(vector<vector<int>> &intervals,
                                       vector<int> &newInterval) {
        // code here
        vector<vector<int>>ans;
        bool isInserted = false;
        
        for (int i=0; i<intervals.size(); i++) {
            if (!isInserted && newInterval[0] < intervals[i][0]) {
                 ans.push_back(newInterval);
                 ans.push_back(intervals[i]);
                 isInserted = true;
            } else {
                ans.push_back(intervals[i]);
            }
        }
        
        if (!isInserted) {
               ans.push_back(newInterval);
        }
        vector<vector<int>>ansFinal;
        ansFinal.push_back(ans[0]);
        
        int res = 0;
        
        for (int i=1; i<ans.size(); i++) {
            if (ans[i][0] <= ansFinal[res][1]) {
                ansFinal[res][0] = min(ansFinal[res][0], ans[i][0]);
                ansFinal[res][1] = max(ansFinal[res][1], ans[i][1]);
            } else {
                ansFinal.push_back(ans[i]);
                res++;
            }
        }
        
        return ansFinal;
    }
};