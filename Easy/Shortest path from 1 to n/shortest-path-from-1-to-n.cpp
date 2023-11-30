//{ Driver Code Starts
//Initial template for c++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    // Function to calculate the minimum steps to reduce a number to 1.
    int minimumStep(int n) {
        // Variable to store the minimum steps.
        int ans = 0;

        // Continue the process until the number becomes 1.
        while (n != 1) {
            // If the number is divisible by 3, divide it by 3.
            if (n % 3 == 0) {
                n /= 3;
            } else {
                // If not divisible by 3, decrement the number by 1.
                n--;
            }

            // Increment the step count.
            ans++;
        }

        // Return the minimum steps.
        return ans;
    }
};


//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.minimumStep(n) << endl;
    
    }
    return 0; 
} 


// } Driver Code Ends