//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int minimumNumberOfDeletions(string S) { 
        // code here
         int n = S.length(); // Get the length of the input string S.
        string Q = S; // Create a copy of string S called Q.
        reverse(Q.begin(), Q.end()); // Reverse the string Q.
        int t[n + 1][n + 1]; // Create a 2D array to store the results of subproblems.

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0 || j == 0) {
                    // Base case: If either of the strings is empty, there are no common characters.
                    t[i][j] = 0;
                } else if (S[i - 1] == Q[j - 1]) {
                    // If the characters at the current positions in S and Q are the same.
                    // Add 1 to the length of the common subsequence and move diagonally.
                    t[i][j] = 1 + t[i - 1][j - 1];
                } else {
                    // If the characters are different, take the maximum of the previous results.
                    t[i][j] = max(t[i - 1][j], t[i][j - 1]);
                }
            }
        }
        // The length of the longest palindromic subsequence is n minus the length of the LCS of S and its reverse Q.
        return n - t[n][n];
    }
    
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string S;
        cin >> S;
        Solution obj;
        cout << obj.minimumNumberOfDeletions(S) << endl;
    }
    return 0;
}
// } Driver Code Ends