//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    string printMinNumberForPattern(string S){
        // code here 
        int n = S.length(); // Get the length of the input string.
        string result; // Initialize a string to store the result.
        stack<int> stk; // Initialize a stack to keep track of numbers.

        // Iterate through the input string and process each character.
        for (int i = 0; i <= n; i++) {
            stk.push(i + 1); // Push the current number onto the stack.

            // Check if the current character is 'I' or the end of the string.
            if (i == n || S[i] == 'I') {
                // Pop elements from the stack and append them to the result string.
                while (!stk.empty()) {
                    result += to_string(stk.top());
                    stk.pop();
                }
            }
        }

        return result; // Return the final result string.
    }
};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
} 

// } Driver Code Ends