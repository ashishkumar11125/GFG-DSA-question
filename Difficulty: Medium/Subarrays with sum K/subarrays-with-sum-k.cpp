class Solution {
  public:
    int cntSubarrays(vector<int> &arr, int k) {
        // code here
        unordered_map<int, int> prefixSumCount;
        int count = 0, prefixSum = 0;
        
        for (int num : arr)
        {
            prefixSum += num;
            count += prefixSum == k; 
            count += prefixSumCount[prefixSum - k]; 
            prefixSumCount[prefixSum]++; 
        }
        
        return count;
    }
};