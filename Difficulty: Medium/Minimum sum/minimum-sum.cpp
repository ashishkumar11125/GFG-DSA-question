class Solution {
  public:
    void CountingSort(vector<int> &arr , vector<int> &tempArr){
        for (int it : arr) tempArr[it]++;
        int j =0 ;
        for (int i = 0 ; i < 10 ; i++) {
            while (tempArr[i] != 0){
                tempArr[i]--;
                arr[j++]=i;
            }
        }
    }
    string minSum(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<int> tempArr(10,0);
        
        CountingSort(arr,tempArr);
        string ans = "";
        int c= 0 ;
        for (int i = n-1 , j = n-2 ; i >= 0 || j >= 0 ; i-=2 , j-=2 ){
            if(arr[i]==0 && arr[j]==0 ) break ; 
            else if(i < 0 && arr[j] == 0 ) break ; 
            else if(j < 0 && arr[i] == 0 ) break ; 
            int temp = arr[i]+arr[j];
            if(c == 1){
                temp++ ;
                c = 0 ;
            }
            int t = temp % 10 ;
            ans += (t+'0');
            if(temp >= 10 ) c=1;
        }
        if(c==1) ans += '1';
        reverse(ans.begin(),ans.end());
        
        return ans ;
    }
};