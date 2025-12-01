class Solution {
  public:
    int subarrayXor(vector<int>& arr) {
        // code here
         int n = arr.size();
        int _xor = 0;
        for(int i = 0;i<n;i++){
            if((i+1)%2 and (n-i)%2)_xor^=arr[i];
        }
        return _xor;
    }
};