class Solution {
  public:
    void setMatrixZeroes(vector<vector<int>> &mat) {
        // code here
        int i,j;
        int r=mat.size(),c=mat[0].size();
        vector<int> row(r,0);
        vector<int> col(c,0);
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                if(mat[i][j] == 0)
                {
                    row[i]=1;
                    col[j]=1;
                }
            }
        }
        for(i=0;i<r;i++)
        {
            if(row[i] == 1)
            {
                for(j=0;j<c;j++)
                {
                    mat[i][j]=0;
                }
            }
        }
        
        for(i=0;i<c;i++)
        {
            if(col[i] == 1)
            {
                for(j=0;j<r;j++)
                {
                    mat[j][i]=0;
                }
            }
        }
    }
};