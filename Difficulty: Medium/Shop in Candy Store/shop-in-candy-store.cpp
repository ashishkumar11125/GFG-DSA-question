class Solution {
  public:
    vector<int> minMaxCandy(vector<int>& arr, int k) {
        // Code here
         vector<int>ans;
        int elementUsed = 0;
        int totalSum =0;
        sort(arr.begin(),arr.end());
        int start = 0;
        while(elementUsed < arr.size())
        {
            totalSum+=arr[start];
            if(k==0)
            {
                elementUsed+=1;
            }
            else
            {
            elementUsed = elementUsed + k +1;
            }
            start++;
        }
        ans.push_back(totalSum);
        elementUsed = 0;
        int end = arr.size()-1;
        totalSum = 0;
        while(elementUsed < arr.size())
        {
            totalSum += arr[end];
            if(k==0)
            {
                elementUsed+=1;
            }
            else{
            elementUsed=k + elementUsed + 1;
            }
            end--;
        }
        ans.push_back(totalSum);
        return ans;
    }
};