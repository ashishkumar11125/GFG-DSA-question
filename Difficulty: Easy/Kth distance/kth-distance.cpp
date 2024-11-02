//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:

    bool checkDuplicatesWithinK(vector<int>& arr, int k) {
        // your code
        unordered_set<int> seen;

    for (int i = 0; i < arr.size(); i++) {
        // If we find arr[i] in the set, it means a duplicate exists within distance `k`
        if (seen.find(arr[i]) != seen.end()) {
            return true;
        }

        // Add the current element to the set
        seen.insert(arr[i]);

        // Remove the element that is out of the `k` distance range
        if (i >= k) {
            seen.erase(arr[i - k]);
        }
    }

    // No duplicates within the distance `k` were found
    return false;
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
        Solution obj;
        bool res = obj.checkDuplicatesWithinK(arr, k);
        if (res)
            cout << "true" << endl;
        else
            cout << "false" << endl;
        // cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends