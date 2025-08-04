class Solution {
  public:
    bool isPalinSent(string &s) {
        // code here
         int n = s.length();
        string res ="";
        
        for(int i =0;i<n;i++){
            if(isalnum(s[i])){
                res += tolower(s[i]);
            }
        }
        
        int l=0,r=res.length()-1;
        while(l<r){
            if(res[l] != res[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};