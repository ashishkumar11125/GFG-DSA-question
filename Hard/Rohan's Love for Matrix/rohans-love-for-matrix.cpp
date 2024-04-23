//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
      int mod=1e9+7;
    int firstElement(int n) {
        // code here
        int a10=1,a11=0;
        for(int i=0;i<n-1;i++){
            int temp=a10+a11;
            a11=a10;
            a10=temp%mod;
        } 
        return a10;
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
        cout << ob.firstElement(n) << endl;
    }
    return 0;
}

// } Driver Code Ends