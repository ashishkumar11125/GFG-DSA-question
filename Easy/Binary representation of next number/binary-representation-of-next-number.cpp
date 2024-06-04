//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string binaryNextNumber(string s) {
        // code here.
        int st=0;
        for(int i=0;i<s.size();i++){
            if(s[i]!='1')st++;
           else break;
        }
        s.erase(0,st);
        
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]!='1'){
                s[i]='1';
                return s;
            }
            else s[i]='0';
        }
        return "1"+s;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.binaryNextNumber(s);
        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends