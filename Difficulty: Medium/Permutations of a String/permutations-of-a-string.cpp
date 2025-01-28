//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
        // Code here there
         set<string>solve(string &s){
      set<string>a;
      sort(s.begin(),s.end());
      do{
          a.insert(s);
      }while (next_permutation(s.begin(),s.end()));
      return a;
  }
    vector<string> findPermutation(string &s) {
       vector<string>ans;
        set<string>a=solve(s);
        for(string str: a){
            ans.push_back(str);
        }
        return ans;
    }
    
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        vector<string> ans = ob.findPermutation(S);
        sort(ans.begin(), ans.end());
        for (auto i : ans) {
            cout << i << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends