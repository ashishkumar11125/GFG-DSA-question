class Solution {
  public:
    int maxSumSubarray(vector<int>& arr) {
        // code here
          int n = arr.size();
        
        int ans = arr[0], keep = arr[0], rem = 0;
        
        for (int i = 1; i < n; i++) {
            rem = max(rem + arr[i], keep);
            keep = max(keep + arr[i], arr[i]);
            
            ans = max(ans, max(keep, rem));
        }
        
        return ans;
    }
};