//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int pairWithMaxSum(vector<int>& arr) {
        // code here
        if(arr.size()<2){
            return -1;
        }
        int max=0;
        for(int j=0;j<arr.size()-1;j++){
            if(arr[j]+arr[j+1]>max){
                    max=(arr[j]+arr[j+1]);
                }
            }
        
        return max;
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();

    while (tc--) {
        string input;
        getline(cin, input);

        stringstream ss(input);
        vector<int> a;
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution obj;
        int res = obj.pairWithMaxSum(a);
        cout << res << endl;
    }
}
// } Driver Code Ends