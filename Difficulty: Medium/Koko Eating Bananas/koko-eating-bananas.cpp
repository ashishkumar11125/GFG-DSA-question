//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int Solve(vector<int>& arr, int k) {
        // Code here
        int l=1,h=1000000000;
        while(l<h){
            int mid=(l+h)/2,res=0;
            for(int x:arr)res+=(x+mid-1)/mid;
            if(res>k)l=mid+1;
            else h=mid;
        }
        return l;
    }
};

//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;

        cout << ob.Solve(arr, k);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends