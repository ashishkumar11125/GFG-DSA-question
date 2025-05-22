
class Solution {
  public:
    void swapKth(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        swap(arr[k-1],arr[n-k]);
        
    }
};


