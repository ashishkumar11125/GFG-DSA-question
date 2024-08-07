//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
     int longestKSubstr(string s, int k) {
    int i =0;
    int j =0;
    int length=0;
    unordered_map<int,int>mpp;
    while(j<s.size()){
        mpp[s[j]]++;
        if(mpp.size()>k){
            mpp[s[i]]--;
            if(mpp[s[i]]==0){
                mpp.erase(s[i]);
            }
            i++;
        }
       else if(mpp.size()==k){
            length=max(length,j-i+1);
        }        
        j++;
    }
    if(length==0) return -1;
    return length;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends