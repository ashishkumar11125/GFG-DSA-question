class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
         int n = s.size(),ans = 0;
        int l = 0,r = 0;
        vector<int> v(26,0);
        while(r < n){
            v[s[r] - 'a']++;
            int cnt = 0;
            for(auto it : v){
                if(it > 0) cnt++;
            }
            while(cnt > k){
                v[s[l] - 'a']--;
                if(v[s[l] - 'a'] == 0) cnt--;
                l++;
            }
            if(cnt == k) ans = max(ans,r - l + 1);
            r++;
        }
        return (ans == 0 ? -1 :  ans);
    }
};