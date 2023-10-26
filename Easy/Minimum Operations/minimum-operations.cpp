//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    int minOperation(int n)
    {
        //code here.
         // Initialize a variable to keep track of the number of operations.
        int count = 0;

        // Continue the loop until n becomes 0.
        while (n > 0)
        {
            // If n is odd (the least significant bit is 1), subtract 1 from n.
            if (n & 1)
                n--;
            // If n is even (the least significant bit is 0), divide it by 2.
            else
                n /= 2;

            // Increment the operation count.
            count++;
        }

        // Return the total number of operations performed.
        return count;
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
	        cin>>n;
	        Solution ob;
	        cout<<ob.minOperation(n)<<endl;
	    }
}
// } Driver Code Ends