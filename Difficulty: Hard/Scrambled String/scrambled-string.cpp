//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

//Back-end complete function Template for C++

class Solution{
    public:
    unordered_map<string,bool>dp;
    bool solveUsingRe(string s1,string s2){
        if(s1==s2)return true;
        if(s1.length()!=s2.length())return false;
        string key=s1+"_"+s2;
        if(dp.find(key)!=dp.end())return dp[key];
        
        bool result=false;
        int n=s1.size();
        
        for(int i=1;i<n;i++){
            bool swapped=solveUsingRe(s1.substr(0,i),s2.substr(n-i,i))&&solveUsingRe(s1.substr(i,n-i),s2.substr(0,n-i));
            if(swapped){
                result=true;
                break;
            }
            bool not_swapped=solveUsingRe(s1.substr(0,i),s2.substr(0,i))&&solveUsingRe(s1.substr(i,n-i),s2.substr(i,n-i));
            if(not_swapped){
                result=true;
                break;
            }
        }
            return dp[key]=result;
    }
    bool isScramble(string s1, string s2){
        dp.clear();
       return solveUsingRe(s1,s2);
    }    
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        string S1, S2;
        cin>>S1>>S2;
        Solution ob;
        
        if (ob.isScramble(S1, S2)) {
            cout << "Yes";
        }
        else {
            cout << "No";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends