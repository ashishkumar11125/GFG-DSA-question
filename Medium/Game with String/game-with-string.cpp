//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        // code here
        vector<int> freq(26,0);
        priority_queue<int> pq;
        for(int i = 0; i < s.length(); i++){
            freq[s[i]-'a']++;
        }
        for(int i = 0; i<26; i++){
            if(freq[i] != 0){
                pq.push(freq[i]);
            }
        }
        while(k--){
            int top = pq.top();
            pq.pop();
            pq.push(top-1);
        }
        int res = 0;
        while(!pq.empty()){
            int x = pq.top();
            pq.pop();
            res += (x*x);
        }
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends