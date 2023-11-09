#include<bits/stdc++.h>
//User function Template for C++
using namespace std;
class Solution{
    public:
    /*Function to count zeros in each column
    * N : Number of rows and columns in array
    M is the matrix that is globally declared
    */
    int columnWithMaxZeros(vector<vector<int>>arr,int N){
        
        // Your code here
        pair<int, int> ans = make_pair(-1, 0); // Initialize a pair to store the result (column index, count of zeros).

        // Iterate through each column in the matrix.
        for (int i = 0; i < N; i++) {
            int count = 0; // Initialize a variable to store the count of zeros in the current column.

            // Iterate through each element in the current column.
            for (int j = 0; j < N; j++) {
                if (arr[j][i] == 0) {
                    count++; // Increment the count if the element is zero.
                }
            }

            // Check if the current column has more zeros than the previous maximum.
            if (count > ans.second) {
                ans.first = i; // Update the index of the column with the maximum zeros.
                ans.second = count; // Update the maximum count of zeros.
            }
        }

        return ans.first; // Return the index of the column with the maximum number of zeros.
    }
};