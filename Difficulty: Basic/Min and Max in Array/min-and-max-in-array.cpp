//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    pair<long long, long long> getMinMax(vector<long long int> arr) {
        // code here
        long long min_element = LLONG_MAX;
        long long max_element = LLONG_MIN;
        
        // Iterate through the array to find min and max
        for (long long num : arr) {
            if (num < min_element) {
                min_element = num;
            }
            if (num > max_element) {
                max_element = num;
            }
        }
        
        // Return the result as a pair
        return {min_element, max_element};
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<long long int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        pair<long long, long long> pp = ob.getMinMax(arr);
        cout << pp.first << " " << pp.second << endl;
    }
    return 0;
}
// } Driver Code Ends