//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    string ntos(string s){
        int pos = s.find(']');
        if(pos == -1){
            return s;
        }
        int x = pos - 1,cnt = 0; 
        string eb = s.substr(pos+1);
        string innerStr = "";
        //get inner string
        while(x>=0){
            if((s[x] == '[' )){
                break;
            }
            innerStr.push_back(s[x]);
            x--;
        }
        reverse(innerStr.begin(), innerStr.end());
        //get count
        int y = x-1;
        string ct =""; 
        while(y>=0){
            if(isdigit(s[y])){
                ct.push_back(s[y]);
                y--;
            }
            else{
                break;
            }
        }
        reverse(ct.begin(), ct.end());
        string ef = s.substr(0,y+1);
        int c = ct.empty() ? 0 : stoi(ct);
        string t="";
        while(c>0){
            t = t + innerStr;
            c--;
        }
        string res = ef + t + eb;
        res = ntos(res);
        return res;
    
    }
    string decodedString(string &s) {
        // code here
        return ntos(s);
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
        cout << ob.decodedString(s) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends