class Solution {
public:
    // Function to return a list of integers visited in snake pattern in a matrix.
    vector<int> snakePattern(vector<vector<int>> matrix) {
        vector<int> answer; // Create a vector to store the integers in snake pattern.
        int x = matrix.size(); // Get the size of the matrix (assuming it's a square matrix).

        // Iterate through the rows of the matrix.
        for (int i = 0; i < x; i++) {
            if (i % 2 == 0) {
                // If the row index is even (0-based), traverse the row from left to right.
                for (int j = 0; j < x; j++) {
                    answer.push_back(matrix[i][j]); // Add the element to the answer vector.
                }
            } else {
                // If the row index is odd, traverse the row from right to left.
                for (int j = x - 1; j >= 0; j--) {
                    answer.push_back(matrix[i][j]); // Add the element to the answer vector.
                }
            }
        }

        return answer; // Return the vector containing the integers in snake pattern.
    }
};