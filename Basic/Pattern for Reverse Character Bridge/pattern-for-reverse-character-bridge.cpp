//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    vector<string> revCharBridge(int N) {
        // code here
        vector<string>ans;
        for(int i =1;i<=N;i++){
            char ch = 64;
            string str = "";
            for(int j =1 ;j<=(2*N-1);j++){
                j<=(N*2)/2?ch++:ch--;
                if(j<=N-i+1 || j>=N-1+i){
                    str += ch;
                }else{
                    str += " ";
                }
            }ans.push_back(str);
        }return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        vector<string> v = ob.revCharBridge(N);
        
        for(int i=0; i<v.size(); i++)
            cout<<v[i]<<endl;
    }
    return 0;
}
// } Driver Code Ends