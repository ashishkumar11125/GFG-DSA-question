//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> antiDiagonalPattern(vector<vector<int>> matrix) 
    {
        // Code here
        vector<int> ans;
        //upper part
        int n=matrix.size();
        for(int i=0;i<n;i++)
        {
            int row=0;
            int col=i;
            while(row<n and col>=0)
            {
                ans.push_back(matrix[row][col]);
                row++;
                col--;
            }
        }
        
        //lower part
        for(int i=1;i<n;i++)
        {
            vector<int> temp;
            int row=i;
            int col=n-1;
            while(row<n and col>=0)
            {
                ans.push_back(matrix[row][col]);
                row++;
                col--;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> matrix;
        matrix.resize(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> ans = ob.antiDiagonalPattern(matrix);
        for (int i = 0; i < ans.size(); ++i) cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends