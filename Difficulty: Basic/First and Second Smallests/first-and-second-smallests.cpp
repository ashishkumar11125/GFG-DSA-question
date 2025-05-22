class Solution {
  public:
    vector<int> minAnd2ndMin(vector<int> &arr) {
        // code here
        if(arr.size()==1){
            return {-1};
        }
        pair<int ,int>smaller;
        smaller.first=INT_MAX;
        smaller.second=INT_MAX;
        for(int i=0;i<arr.size();i++){
            if(arr[i]<smaller.first){
                smaller.second=smaller.first;
                smaller.first=arr[i];
            }
            else if(arr[i]>smaller.first && arr[i]<smaller.second){
                smaller.second=arr[i];
            }
        }
        if(smaller.second==INT_MAX){
            return {-1};
        }
        
  return {smaller.first,smaller.second} ; 
    }
};