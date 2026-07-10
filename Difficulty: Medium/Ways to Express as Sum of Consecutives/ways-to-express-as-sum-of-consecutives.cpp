class Solution {
  public:
    int getCount(int n) {
        // code here
        int left = 1, right = 2;
            int sum = 3;
            int count = 0;
        
            while (left < right && left <= n / 2) {
        
                if (sum == n) {
                    count++;
                    sum -= left;
                    left++;
                } else if (sum < n) {
                    right++;
                    sum += right;
                } else {
                    sum -= left;
                    left++;
                }
            }
        
            return count;
    }
};