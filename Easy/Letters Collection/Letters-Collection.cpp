class Solution {
public:
    // Function to calculate the sum of neighboring elements based on queries
    vector<int> matrixSum(int n, int m, vector<vector<int>> mat, int q, vector<int> queries[]) 
    {
        vector<int> ans; // Create a vector to store the results of the queries.

        // Loop through the queries
        for (int k = 0; k < q; k++) 
        {
            int w = queries[k][0]; // Get the query type: 1 or 2
            int i = queries[k][1]; // Get the row index
            int j = queries[k][2]; // Get the column index
            int sum = 0;

            if (w == 1) 
            {
                // Query type 1: Calculate the sum of neighboring elements within a 3x3 grid
                if ((i - 1) >= 0 && (j - 1) >= 0) sum += mat[i - 1][j - 1];
                if ((i - 1) >= 0 && j < m) sum += mat[i - 1][j];
                if ((i - 1) >= 0 && (j + 1) < m) sum += mat[i - 1][j + 1];
                if (i < n && j - 1 >= 0) sum += mat[i][j - 1];
                if (i < n && j + 1 < m) sum += mat[i][j + 1];
                if ((i + 1) < n && (j - 1) >= 0) sum += mat[i + 1][j - 1];
                if ((i + 1) < n && j < m) sum += mat[i + 1][j];
                if ((i + 1) < n && (j + 1) < m) sum += mat[i + 1][j + 1];
                ans.push_back(sum); // Add the sum to the result vector.
            } 
            else 
            {
                // Query type 2: Calculate the sum of elements within a 5x5 grid with certain conditions
                for (int l = i - 2; l <= i + 2; l++) {
                    for (int r = j - 2; r <= j + 2; r++) {
                        if (l >= 0 && l < n && r >= 0 && r < m) {
                            if (abs(l - i) == 2 || abs(r - j) == 2) sum += mat[l][r];
                        }
                    }
                }
                ans.push_back(sum); // Add the sum to the result vector.
            }
        }

        return ans; // Return the vector containing the results of all queries.
    }
};