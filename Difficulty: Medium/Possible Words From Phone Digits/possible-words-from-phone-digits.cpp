class Solution {
  public:
     vector<char> fromNumber(int n) {
        vector<char>ans;
        switch(n) {
            case 2:
            ans = {'a','b','c'};
            return ans;
            case 3:
            ans = {'d','e','f'};
            return ans;
            case 4:
            ans = {'g','h','i'};
            return ans;
            case 5:
            ans = {'j','k','l'};
            return ans;
            case 6:
            ans = {'m','n','o'};
            return ans;
            case 7:
            ans = {'p','q','r','s'};
            return ans;
            case 8:
            ans = {'t','u','v'};
            return ans;
            case 9:
            ans = {'w','x','y','z'};
            return ans;
            default:
            return ans;
        }
    }
  
    void recur(vector<int>&arr, int counter,string &curr,vector<string>&ans) {
        if(counter>=arr.size()) {
            ans.push_back(curr);
            return;
        }
        
        if(arr[counter]==1|| arr[counter]==0) {
            recur(arr,counter+1,curr,ans);
            return;
        }
        vector<char>charArray = fromNumber(arr[counter]);
        for(int i=0;i<charArray.size();i++) {
            curr+=charArray[i];
            recur(arr,counter+1,curr,ans);
            curr.erase(curr.length()-1,1);
        }
    }
    vector<string> possibleWords(vector<int> &arr) {
        // code here
        vector<string>ans;
        string sample="";
        recur(arr,0,sample,ans);
        return ans;
    }
};