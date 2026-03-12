class Solution {
  public:
    int kBitFlips(vector<int>& arr, int k) {
        // code here
         int n = arr.size();
        vector<int> flip(n, 0);
        int currFlip = 0;
        int ans = 0;

        for(int i = 0; i < n; i++) {
            if(i >= k)
                currFlip ^= flip[i-k];

            if((arr[i] ^ currFlip) == 0) {
                if(i + k > n)
                    return -1;

                ans++;
                currFlip ^= 1;
                flip[i] = 1;
            }
        }
        return ans;
    }
};