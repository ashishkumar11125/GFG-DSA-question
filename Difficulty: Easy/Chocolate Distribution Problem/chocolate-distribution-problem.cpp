class Solution {
  public:
    int findMinDiff(vector<int>& a, int m) {
        // code here
        int n=a.size();
        sort(a.begin(),a.end());
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            int j=i+m-1;
            mini=min(mini,j<n ? a[j]-a[i] : INT_MAX);
        }
        return mini;
    }
};