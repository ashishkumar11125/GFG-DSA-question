//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        // code here
        int n = arr.size();
        int left = 0, right = 0;
        long long currentSum = 0;  // Use long long to handle large sums

        for (right = 0; right < n; right++) {
            currentSum += arr[right];

            while (currentSum > target && left < right) {
                currentSum -= arr[left];
                left++;
            }

            if (currentSum == target) {
                return {left + 1, right + 1};  // Return 1-based indices
            }
        }

        return {-1};
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t
    while (t--) {
        vector<int> arr;
        int d;
        string input;

        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        cin >> d;
        cin.ignore(); // Ignore the newline character after d

        Solution ob;
        vector<int> result = ob.subarraySum(arr, d);
        for (int i : result) {
            cout << i << " ";
        }
        cout << "\n~\n";
    }
    return 0;
}

// } Driver Code Ends