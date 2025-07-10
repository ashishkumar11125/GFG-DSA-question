class Solution {
  public:
    string longestString(vector<string> &words) {
        // code here
        sort(words.begin(), words.end());
        map <string, bool> mp;
        mp[""] = true;
        string ans;
        
        for(string s : words){
            string temp = s;
            temp.pop_back();
            if(mp[temp]){
                if(s.length() > ans.length()) ans = s;
                else if(s.length() == ans.length()) ans = min(ans, s);
                
                mp[s] = true;
            }
            else mp[s] = false;
        }
        
        return ans;
    }
};