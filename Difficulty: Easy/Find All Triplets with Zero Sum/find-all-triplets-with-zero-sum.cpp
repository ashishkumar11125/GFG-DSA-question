//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<vector<int>> findTriplets(vector<int> &arr) {
        // Code here'
        unordered_map<int,vector<int>> mp;
        int n=arr.size();
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            mp[arr[i]].push_back(i);
        }
        int i=0,j=2;
        while(i<n-2){
            j=i+2;
            while(j<n){
                int req=0-arr[i]-arr[j];
                for(auto x:mp[req]){
                    if(x>i && x<j)
                    ans.push_back({i,x,j});
                }
                j++;
            }
            i++;
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
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;

        vector<vector<int>> res = ob.findTriplets(arr);
        sort(res.begin(), res.end());
        if (res.size() == 0) {
            cout << "[]\n";
        }
        for (int i = 0; i < res.size(); i++) {
            for (int j = 0; j < res[i].size(); j++) {
                cout << res[i][j] << " ";
            }
            cout << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends