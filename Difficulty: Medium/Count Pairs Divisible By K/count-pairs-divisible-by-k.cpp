class Solution {
  public:
    int countKdivPairs(vector<int>& arr, int k) {
        // code here
         int n = arr.size();
        
        int target = k;
        
        int cnt = 0;
            
        unordered_map<int,int>mp;
          
        for(int i=0; i<n; i++){
            
            arr[i] = arr[i]%k;
        }
        
        
        // 2 sum problem logic
        int zeors = 0;
        
        for(int i=0; i<n; i++){
            
            
            if(arr[i] == 0) zeors++;
            
            int key = target -arr[i];
            
            if(mp.find(key) != mp.end()){
                
                cnt+= mp[key];
            }
            
            mp[arr[i]]++;
        }
        
        cnt+= (zeors)*(zeors-1)/2;
        
        
        return cnt;
    }
};