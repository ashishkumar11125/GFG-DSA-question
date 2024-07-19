//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:

     
    string longestCommonPrefix(vector<string> arr) {
        string ans="-1";
        for(int i=0;i<arr[0].size();i++){
            string s1=arr[0].substr(0,i+1);
            for(int j=1;j<arr.size();j++){
                string s2=arr[j].substr(0,i+1);
                if(s1!=s2){
                    return ans;
                }
            }
            ans=s1;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.longestCommonPrefix(arr) << endl;
    }
}

// } Driver Code Ends