class Solution {
  private:
  
    vector<int> PGE(vector<int>&arr){
        int n=arr.size();
        stack<int>st;
        vector<int>pge(arr.size(),-1);
        
        for(int i=0;i<n;i++){
            
            while(!st.empty() && arr[st.top()]<arr[i]){
                st.pop();
            }
            
            if (!st.empty()) pge[i]=st.top();
            st.push(i);
        }
        
        return pge;
        
    }   
    
    vector<int> NGE(vector<int>&arr){
        int n=arr.size();
        stack<int>st;
        vector<int>nge(arr.size(),n);
        
        for(int i=n-1;i>=0;i--){
            
            while(!st.empty() && arr[st.top()]<arr[i]){
                st.pop();
            }
            
            if (!st.empty()) nge[i]=st.top();
            st.push(i);
        }
        
        return nge;
        
    }
    
    
  public:
    int maxPeople(vector<int> &arr) {
        // code here
        int n=arr.size();
        
        vector<int> pge=PGE(arr);
        vector<int> nge=NGE(arr);
        
        
        int ans=0;
        
        for(int i=0;i<n;i++){
            int left=(pge[i] == -1 ? 0 : pge[i]+1);
            int right=(nge[i] == n ? n-1 : nge[i]-1);
            
            int cnt=right-left+1;
            
            ans=max(ans,cnt);
        }
        
        return ans;

    }
};