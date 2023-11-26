//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    // Function to generate a specific pattern based on the input N.
    vector<int> pattern(int N) {
        vector<int> ans; // Vector to store the pattern elements.
        bool let = false; // Flag to switch between decreasing and increasing.

        while (1) {
            if (N <= 0)
                let = true;

            if (!let) {
                ans.push_back(N); // Add the current element to the pattern.
                N -= 5; // Decrease N by 5.
            } else {
                ans.push_back(N); // Add the current element to the pattern.
                if (N == ans[0])
                    break; // Break the loop if we have reached the starting element.
                N += 5; // Increase N by 5.
            }
        }

        return ans; // Return the generated pattern.
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> ans = ob.pattern(N);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends