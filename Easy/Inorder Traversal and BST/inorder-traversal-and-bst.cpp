//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int isRepresentingBST(int arr[], int N) // Function to check if the given array is representing a Binary Search Tree (BST).
    {
        // code here
        // Iterate through the array and check if each element is greater than its predecessor.
        for (int i = 1; i < N; i++){
            // If any element is not greater than or equal to its predecessor, return 0 (not representing a BST).
            if(arr[i-1] >= arr[i])
            return 0;
        }
        // If all elements satisfy the BST property, return 1 (representing a BST).
        return 1;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int arr[N];
        for(int i=0;i<N;i++)cin>>arr[i];
        Solution ob;
        cout<<ob.isRepresentingBST(arr,N)<<endl;
    }
    return 0;
}
// } Driver Code Ends