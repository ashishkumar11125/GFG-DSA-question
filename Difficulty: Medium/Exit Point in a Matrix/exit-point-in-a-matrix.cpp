class Solution {
  public:
    vector<int> exitPoint(vector<vector<int>>& mat) {
        // code here
        int n=mat.size();
        int m=mat[0].size();
        
        map<char, char>dir_ch={{'W','S'}, {'S','E'}, {'E','N'}, {'N','W'}};
        map<char, pair<int, int>>dir={ {'W',{0, 1}}, {'S',{1, 0}}, {'E',{0, -1}}, {'N',{-1, 0}} };
        
        int r=0, c=0;
        char d='W';
        
        while(r<n && c<m){
            if(mat[r][c]==0){
                int nr=r+dir[d].first;
                int nc=c+dir[d].second;
                if(nr>=0 && nr<n && nc>=0 && nc<m){
                    r=nr;
                    c=nc;
                }else return {r, c};
            }else{
                d=dir_ch[d];
                mat[r][c]=0;
            }
        }
        return {-1, -1};
    }
};