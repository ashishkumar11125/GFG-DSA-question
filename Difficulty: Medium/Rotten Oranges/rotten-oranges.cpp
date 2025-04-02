//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int orangesRotting(vector<vector<int>>& mat) {
        // Code here
        int n = mat.size();
        int m = mat[0].size();
        
        // Queue to store {row, col, time}
        queue<pair<pair<int,int>, int>> q;
        int freshCount = 0;
        
        // Initial scan: count fresh oranges and add rotten ones to queue
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 2) {
                    q.push({{i,j}, 0});  // Rotten orange with time 0
                }
                else if(mat[i][j] == 1) {
                    freshCount++;  // Count fresh oranges
                }
            }
        }
        
        // If no fresh oranges, return 0
        if(freshCount == 0) return 0;
        
        // Directions: up, right, down, left
        int directions[4][2] = {{-1,0}, {0,1}, {1,0}, {0,-1}};
        int maxTime = 0;
        int rottenCount = 0;
        
        // BFS to rot adjacent oranges
        while(!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int time = q.front().second;
            q.pop();
            
            maxTime = max(maxTime, time);
            
            // Check all 4 adjacent cells
            for(int i = 0; i < 4; i++) {
                int newRow = row + directions[i][0];
                int newCol = col + directions[i][1];
                
                // Check if position is valid and has fresh orange
                if(newRow >= 0 && newRow < n && 
                   newCol >= 0 && newCol < m && 
                   mat[newRow][newCol] == 1) {
                    mat[newRow][newCol] = 2;  // Rot the orange
                    q.push({{newRow, newCol}, time + 1});
                    rottenCount++;
                }
            }
        }
        
        // If all fresh oranges are rotten, return time, else -1
        return (rottenCount == freshCount) ? maxTime : -1;
        
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        int ans = obj.orangesRotting(mat);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends