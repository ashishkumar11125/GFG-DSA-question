//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// #define ll long long
class Solution {
public:
    // Function to generate the nth row of Pascal's Triangle modulo 10^9 + 7.
    vector<long long> nthRowOfPascalTriangle(int n) {
        // code here
        // Create a vector to store the elements of the nth row of Pascal's Triangle.
        vector<long long> A(n, 0);

        // The first element of each row is always 1.
        A[0] = 1;

        // Modulo value for the result.
        long long m = pow(10, 9) + 7;

        // Loop through each element of the row starting from the second element.
        for (long long i = 1; i < n; i++) {
            // Iterate from the current element to the second element.
            for (long long j = i; j >= 1; j--) {
                // Update the current element using the sum of the two elements above it.
                A[j] = (A[j] + A[j - 1]) % m;
            }
        }

        // Return the generated row of Pascal's Triangle.
        return A;
    }
};


//{ Driver Code Starts.


void printAns(vector<long long> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends