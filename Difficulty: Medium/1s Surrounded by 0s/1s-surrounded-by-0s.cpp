class Solution {
  public:
    vector<vector<int>> directions{{1,0}, {0,1}, {-1, 0}, {0, -1}};
    
    void dfs(int i, int j, int m, int n, vector<vector<int>>& grid) {
        
        if (i >= m || i < 0 || j >= n || j < 0 || grid[i][j] != 1) {
            return;
        }
        
        grid[i][j] = -1;
 
        
        for (auto& dir : directions) {
            int x = i + dir[0];
            int y = j + dir[1];
            
            dfs(x, y, m, n, grid);
        }
        
        return;
    }
    int cntOnes(vector<vector<int>>& grid) {
        // code here
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        
        // first row and last row
        
        for (int j=0; j<n; j++) {
            
            if (grid[0][j] == 1) {
                dfs(0, j, m, n, grid);
            }
            
            if (grid[m-1][j] == 1) {
                dfs(m-1, j, m, n, grid);
            }
        }
        
        // first col and last col
        
        for (int i=0; i<m; i++) {
            
            if (grid[i][0] == 1) {
                dfs(i, 0, m, n, grid);
            }
            if (grid[i][n-1] == 1) {
                dfs(i, n-1, m, n, grid);
            }
        }
        
        int count = 0;
        
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (grid[i][j] == 1) count++;
            }
        }
        
        return count;
    }
    
};