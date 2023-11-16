//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
public:
    vector<int> F; // Vector to mark visited states during DFS
    string R; // String to store the result
    int p, k; // Variables to store pow(k, n-1) and k

    // Depth-First Search (DFS) function to find the string
    bool dfs(int v, int c) {
        if (!c) return true; // If the target count is reached, return true

        // Iterate through all possible digits (0 to k-1)
        for (int d = 0; d < k; d++) {
            int vn = v % p * k + d; // Calculate the next state
            if (!F[vn]) {
                F[vn] = 1; // Mark the state as visited
                R.push_back('0' + d); // Add the digit to the result string

                // Recursive call to explore the next state
                if (dfs(vn, c - 1)) return true;

                F[vn] = 0; // Backtrack: Mark the state as not visited
                R.pop_back(); // Backtrack: Remove the last digit from the result string
            }
        }
        return false; // If no valid digit is found, return false
    }

    // Function to find the string of length n with digits in the range [0, k-1]
    string findString(int n, int k) {
        // code here
        
        int N = (int)pow(k, n); // Calculate the total number of possible states
        this->k = k; // Set the value of k
        p = (int)pow(k, n - 1); // Calculate pow(k, n-1)
        F.resize(N); // Resize the vector to store visited states
        F[0] = 1; // Mark the initial state as visited
        R.assign(n, '0'); // Initialize the result string with '0' characters

        // Start the DFS from the initial state (0) and explore all possible states
        dfs(0, N - 1);

        return R; // Return the result string
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        cin>>N>>K;
        Solution ob;
        string ans = ob.findString(N, K);
        int ok=1;
        for(auto i:ans){
            if(i<'0'||i>K-1+'0')
                ok=0;
        }
        if(!ok){
            cout<<-1<<endl;
            continue;
        }
        unordered_set<string> st;
        for(int i=0;i+N-1<ans.size();i++){
            st.insert(ans.substr(i,N));
        }
        int tot=1;
        for(int i=1;i<=N;i++)
            tot*=K;
        if(st.size()==tot)
        {
            cout<<ans.size()<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    }
    return 0;
} 
// } Driver Code Ends