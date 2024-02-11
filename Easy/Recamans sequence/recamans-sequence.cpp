//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> recamanSequence(int n){
        // code here
        unordered_map<int,int>hmap;
        hmap[0]++;
        vector<int>temp(n);
        temp[0]=0;
        for(int i=1;i<n;i++){
            int k=temp[i-1]-i;
            if(k>0 and hmap.find(k)==hmap.end()){
                temp[i]=k;
                hmap[k]++;
            }
            else{
                temp[i]=temp[i-1]+i;
                hmap[temp[i-1]+i]++;
            }
        }
        return temp;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<int> ans = ob.recamanSequence(n);
        for(int i = 0;i < n;i++)
            cout<<ans[i]<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends