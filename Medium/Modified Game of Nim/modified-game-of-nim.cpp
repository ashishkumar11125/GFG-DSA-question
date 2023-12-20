//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    // Function to find the winner in a game.
    int findWinner(int n, int A[]) {
        // Initialize a variable to store the XOR of all elements.
        int XOR = 0;

        // Calculate the XOR of all elements in the array.
        for (int i = 0; i < n; i++)
            XOR ^= A[i];

        // If the XOR is zero, it means the first player wins (return 1).
        if (!XOR)
            return 1;
        else
            // If the XOR is non-zero, determine the winner based on the parity of the array size.
            // If the array size is even, the second player wins; otherwise, the first player wins.
            return (n % 2) + 1;
    }
};




//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i = 0;i < n;i++)
            cin>>A[i];
        
        Solution ob;
        cout<<ob.findWinner(n, A)<<"\n";
    }
    return 0;
}
// } Driver Code Ends