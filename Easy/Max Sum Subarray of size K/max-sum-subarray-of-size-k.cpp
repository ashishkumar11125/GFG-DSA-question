//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

class Solution {
public:
    // Function to find the maximum sum subarray of size K.
    long maximumSumSubarray(int K, vector<int> &Arr, int N) {
        // Initialize two pointers, i and j, and variables for the maximum sum and the current sum.
        int i = 0, j = 0;
        long long ans = 0, sum = 0;

        // Iterate through the array using the two pointers.
        while (j < N) {
            // Add the current element to the sum.
            sum += Arr[j];

            // If the window size is less than K, move the right pointer.
            if (j - i + 1 < K) {
                j++;
            }
            // If the window size is equal to K, update the maximum sum, subtract the element at i, and move both pointers.
            else if (j - i + 1 == K) {
                ans = max(sum, ans);
                sum -= Arr[i];
                i++;
                j++;
            }
        }

        // Return the maximum sum.
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
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
} 
// } Driver Code Ends