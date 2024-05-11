//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> jugglerSequence(int n) {
        // code here
        int ans = n,i=0;
        vector<int>result;
        result.push_back(n);
        while(ans != 1){
            if(result[i] % 2 ==0){
                ans = floor(pow(result[i],0.5));
                result.push_back(ans);
                i++;
            }
            else{
                ans=floor(pow(result[i],1.5));
                result.push_back(ans);
                i++;
            }
        }
        return result;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        vector<int> ans = ob.jugglerSequence(n);
        for (int u : ans)
            cout << u << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends