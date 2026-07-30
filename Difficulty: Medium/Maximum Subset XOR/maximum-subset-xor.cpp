class Solution {
  public:
    int maxSubsetXOR(vector<int> &arr) {
        // code here
         vector<int> basis(32, 0);
        
        for (int x : arr) {
            
            for (int bit=31; bit>=0; bit--) {
                
                if ((x & (1 << bit)) == 0) continue; // given bit not set
                
                if (basis[bit] == 0) {
                    basis[bit] = x;
                    break;
                }
                
                x ^= basis[bit];
            }
        }
        
        int ans = 0;
        
        for (int bit=31; bit>=0; bit--) {
            
            if ((ans ^ basis[bit]) > ans) {
                ans = (ans ^ basis[bit]);
            }
        }
        
        return ans;
    }
};