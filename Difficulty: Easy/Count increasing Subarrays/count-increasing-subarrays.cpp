class Solution {
  public:
    int countIncreasing(vector<int>& arr) {
        // code here.
        int tc = 0 , cc = 0;
        for(int i = 1 ; i<arr.size() ; i++){
            if(arr[i] > arr[i-1])
                cc++;
            else cc = 0;
            
            tc += cc;
        }
        return tc;
    }
};
