class Solution
{   
    public:
    //Function to return sum of upper and lower triangles of a matrix.
    vector<int> sumTriangles(const vector<vector<int> >& matrix, int n)
    {
        // code here
       // code here
        int upper=0,lower=0;
        for(int i=0;i<n;i++){
            // upper triangle
            for(int j=i;j<n;j++){
                upper+=matrix[i][j];
            }
            // lower triangle
            for(int j=0;j<=i;j++){
                lower+=matrix[i][j];
            }
        }
        return {upper,lower};
    }
};