//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
public:
    // Function to find the minimum possible difference between the heights of the towers after modifying at most k elements.
    int getMinDiff(int arr[], int n, int k) {
        // Sort the array to easily find the minimum and maximum possible heights.
        sort(arr, arr + n);

        // Initialize the initial difference as the difference between the maximum and minimum heights.
        int diff = arr[n - 1] - arr[0];

        // Calculate the least and most possible heights after modifying at most k elements.
        int least = arr[0] + k;
        int most = arr[n - 1] - k;

        // Iterate through the array to find the minimum difference.
        for (int i = 0; i < n - 1; i++) {
            // Calculate the potential minimum and maximum heights after modifying the current element.
            int mini = min(arr[i + 1] - k, least);
            int maxi = max(arr[i] + k, most);

            // If the potential minimum is negative, skip to the next iteration.
            if (mini < 0)
                continue;
            else
                // Update the minimum difference if the potential difference is smaller.
                diff = min(diff, maxi - mini);
        }

        // Return the minimum difference.
        return diff;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends