//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &matrix) {
        // code here
         int top = 0;
        int left = 0;
        int right = matrix[0].size()-1;
        int bottom = matrix.size()-1;
        int totalElements = ( matrix.size() * matrix[0].size() );
        vector<int> ans;
        
        if (matrix.empty() || matrix[0].empty()) {
        return ans; // Return an empty vector for an empty matrix
        }
        
        while(totalElements > 0 ){
            
            // top
            for(int j=left; j<=right && totalElements>0; j++){
                ans.push_back(matrix[top][j]);
                totalElements--;
            }
            top++;
            // right
            for(int i=top; i<=bottom && totalElements>0; i++){
                ans.push_back(matrix[i][right]);
                totalElements--;
            }
            right--;
            //bottom 
            for(int j=right; j>=left && totalElements>0; j--){
                ans.push_back(matrix[bottom][j]);
                totalElements--;
            }
            bottom--;
            //left
            for(int i=bottom; i>=top && totalElements>0; i--){
                ans.push_back(matrix[i][left]);
                totalElements--;
            }
            left++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c, 0));

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends