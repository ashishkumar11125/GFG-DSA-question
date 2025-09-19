class Solution {
  public:
    int minParentheses(string& s) {
        // code here
        stack<char> st;
        int c = 0;

        for (auto a : s) {
            if (a == '(') {
                st.push(a);
            } else { 
                if (!st.empty() && st.top() == '(') {
                    st.pop(); 
                } else {
                    c++;
                }
            }
        }
        return c + st.size(); 
    }
};