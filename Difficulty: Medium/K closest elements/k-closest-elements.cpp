class Solution {
  public:
    vector<int> printKClosest(vector<int> arr, int k, int x) {
        // Code here
         int n=arr.size();
        int index=-1;
        bool flag=true;
        for(int i=0;i<n;i++)
        {
            if(flag&&arr[i]>=x)
            {
                index=i;
                flag=false;
            }
            
            if(arr[i]<x)
            arr[i]=x-arr[i];
            else
            arr[i]-=x;
        }
        
        int i,j;
        vector<int>ans;
        if(index==-1)
        {
            i=n-1;
            j=n;
        }
        else if(arr[index]==0)
        {
            i=index-1;
            j=index+1;
        }
        else
        {
            i=index-1;
            j=index;
        }
        while(k>0&&i>=0&&j<n)
        {
            if(arr[i]<arr[j])
            {
                ans.push_back(x-arr[i]);
                i--;
            }
            else
            {
                ans.push_back(x+arr[j]);
                j++;
            }
            k--;
        }
        while(k>0&&i>=0)
        {
            ans.push_back(x-arr[i]);
            i--;
            k--;
        }
        while(k>0&&j<n)
        {
            ans.push_back(x+arr[j]);
            j++;
            k--;
        }
        
        return ans;

    }
};