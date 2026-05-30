class Solution {
  public:
    void replaceElements(vector<int>& arr) {
        // code here
        int n=arr.size();
        int prv=arr[0];
        for(int i=0; i<n; i++){
            if(i==0){
                arr[i]^=arr[i+1];
            }else if(i==n-1){
                arr[i]^=prv;
            }else{
                int tmp=prv^arr[i+1];
                prv=arr[i];
                arr[i]=tmp;
            }
        }
    }
    
};