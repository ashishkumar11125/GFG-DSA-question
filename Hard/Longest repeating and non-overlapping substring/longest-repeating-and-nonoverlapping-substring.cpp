//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    string longestSubstring(string s, int n) {
        // code here
        if(n == 1)
        {
            return "-1";
        }
        
        int len = 0;
        string ans = "";
        
        for(int i =0; i<n; i++)
        {
            for(int j = i+1; j<=n; j++)
            {
                if(j-i <= len)
                {
                    continue;
                }
                
            
                
                string a = s.substr(i, j-i);
                string b = s.substr(j, n-j);
                
                
                if(b.find(a) != string::npos)
                {
                    ans = a;
                    len = a.length();
                }
                
                else
                {
                    break;
                }
            }
        }
        
        if(ans.length() == 0)
        {
            return "-1";
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        string S;

        cin >> N;
        cin >> S;

        Solution ob;
        cout << ob.longestSubstring(S, N) << endl;
    }
    return 0;
}
// } Driver Code Ends