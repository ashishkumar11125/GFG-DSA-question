class Solution {
  public:
    string firstNonRepeating(string &s) {
        // code here
        vector<vector<int>> vec(26);
        string res = "";
        for(int i=0;i<s.size();i++)
        {
            vec[s[i]-'a'].push_back(i);
            char nr = '#';
            int pos = INT_MAX;
            for(int i=0;i<26;i++)
            if(vec[i].size()==1 && vec[i][0]<pos)
            {
                pos = vec[i][0];
                nr = (char)('a'+i);
            }
            res += nr;
        }
        return res;
    }
};