//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
        bool isWordExist(vector<vector<char>>& mat, string& word) {
        if (mat.empty() || mat[0].empty()) return false;
        int m = mat.size();
        int n = mat[0].size();
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == word[0]) {
                    char temp = mat[i][j];
                    mat[i][j] = '#'; // Mark as visited
                    if (dfs(mat, word, i, j, 0)) {
                        mat[i][j] = temp; // Restore before returning
                        return true;
                    }
                    mat[i][j] = temp; // Restore
                }
            }
        }
        return false;
    }

private:
    bool dfs(vector<vector<char>>& mat, string& word, int i, int j, int index) {
        if (index == word.size() - 1) {
            return true;
        }
        
        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for (auto& dir : dirs) {
            int ni = i + dir.first;
            int nj = j + dir.second;
            
            if (ni >= 0 && ni < mat.size() && nj >= 0 && nj < mat[0].size() && mat[ni][nj] == word[index + 1]) {
                char temp = mat[ni][nj];
                mat[ni][nj] = '#'; // Mark as visited
                if (dfs(mat, word, ni, nj, index + 1)) {
                    mat[ni][nj] = temp; // Restore before returning
                    return true;
                }
                mat[ni][nj] = temp; // Restore
            }
        }
        return false;
    }
    
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> mat(n, vector<char>(m, '*'));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];
        string word;
        cin >> word;
        Solution obj;
        bool ans = obj.isWordExist(mat, word);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends