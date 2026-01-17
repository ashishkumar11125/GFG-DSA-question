class Solution {
  public:
    bool checkRedundancy(string &s) {
        // code here
        stack<char> stk;

        for(int i=0;i<s.size();i++){
            if(s[i]=='(')stk.push('(');
            else if(s[i]==')'){
                if(stk.top()=='(')return true;
                while(stk.size() && stk.top()!='(')stk.pop();
                stk.pop();
            }
            else if(isalpha(s[i]))continue;
            else stk.push(s[i]);
        }
        
        return false;
    }
};
