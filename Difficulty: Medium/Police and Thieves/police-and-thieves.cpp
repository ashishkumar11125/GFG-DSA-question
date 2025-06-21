class Solution {
  public:
    int catchThieves(vector<char> &arr, int k) {
        // Code here
        queue<int>T,P;
        for(int i=0;i<arr.size();i++)
            arr[i]=='P'?P.push(i):T.push(i);
        int ans=0;
        while(T.empty()==false && P.empty()==false){
            int iT=T.front();
            int iP=P.front();
            if(iP>=iT){
                if(iT+k>=iP)
                ans++,P.pop(),T.pop();
                else T.pop();
            }
            else{
                if(iP+k>=iT)
                ans++,P.pop(),T.pop();
                else P.pop();
            }
        }
        return ans;
    }
};