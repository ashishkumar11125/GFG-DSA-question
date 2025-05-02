//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++
class Solution {
  public:
    int findMaximum(vector<int> &arr) {
        // code here
        int start=0;
        int end=arr.size()-1;
        int ans=0;
        while(start<=end){
            int mid=start+(end-start)/2;
            if((mid==arr.size()-1||arr[mid]>arr[mid+1])&&(mid==0||arr[mid]>arr[mid-1])){
                ans= arr[mid];
            }
            if(mid>0 && arr[mid]>arr[mid+1]){ 
                //mid<arr.size()-1&&arr[mid]<arr[mid+1]
                end=mid-1;
            }
            else{
                start=mid+1;
            }
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
        int value;

        // Read the entire line of integers
        string line;
        // cin.ignore(); // Ignore the newline after the test case input
        getline(cin, line);
        stringstream ss(line);

        // Parse integers and add them to the vector
        while (ss >> value) {
            arr.push_back(value);
        }

        Solution ob;
        auto ans = ob.findMaximum(arr);
        cout << ans << "\n";
        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends