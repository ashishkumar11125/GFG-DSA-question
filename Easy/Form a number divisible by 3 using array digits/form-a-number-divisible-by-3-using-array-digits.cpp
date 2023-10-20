//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution 
{
  public:
    int isPossible(int N, int arr[])
    {
        // code here
        int num = 0; // Initialize a variable to keep track of the sum of remainders.

        for (int i = 0; i < N; i++) 
        {
        // Calculate the remainder of each element when divided by 3 and add it to 'num'.

            num += (arr[i] % 3);
        }

        // Check if the sum of remainders is divisible by 3 (i.e., num % 3 equals 0).
        // If it is, return 1 (indicating it is possible), otherwise return 0.
        return (num % 3 == 0) ? 1 : 0;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) cin >> arr[i];

        Solution ob;
        cout << ob.isPossible(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends