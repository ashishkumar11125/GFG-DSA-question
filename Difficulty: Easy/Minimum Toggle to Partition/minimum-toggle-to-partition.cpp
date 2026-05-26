class Solution {
  public:
    int minToggle(vector<int>& arr) {
        // code here
         int n = arr.size();

        int totalOnes = 0;

        for (int x : arr)
            totalOnes += x;

        int ans = INT_MAX;

        int leftOnes = 0;
        int rightOnes = totalOnes;

        // partition before index i
        for (int i = -1; i < n; i++) {

            // move current element to left side
            if (i >= 0) {
                leftOnes += arr[i];
                rightOnes -= arr[i];
            }

            int leftCost = leftOnes;

            int rightLength = n - i - 1;
            int rightZeros = rightLength - rightOnes;

            ans = min(ans, leftCost + rightZeros);
        }

        return ans;
    }
};