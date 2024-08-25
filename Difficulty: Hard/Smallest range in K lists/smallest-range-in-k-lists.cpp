//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define N 1000


// } Driver Code Ends
// you are required to complete this function 
// function should print the required range
class Solution{
    public:
    pair<int,int> findSmallestRange(int arr[][N], int n, int k)
    {
          //code here
          vector<pair<int,int>> vp;
          for (int i=0;i<k;i++){
              for (int j=0;j<n;j++){
                vp.push_back({arr[i][j],i});
              }
          }
          sort(vp.begin(),vp.end());
          map<int,int> mp;
          int i=0;
          int j=0;
          int mini=INT_MAX;
          pair<int,int> p;
          while(i<vp.size() && j<vp.size()){
              mp[vp[j].second]++;
              if (mp.size()==k){
                  if (vp[j].first - vp[i].first + 1 < mini){
                      mini=vp[j].first - vp[i].first + 1;
                      p={vp[i].first,vp[j].first};
                  }
                  while(i<j){
                      mp[vp[i].second]--;
                     
                      if (mp[vp[i].second]==0){
                          mp.erase(vp[i].second);
                          i++;
                          break;
                      }
                      i++;
                      if (vp[j].first - vp[i].first + 1 < mini){
                          mini=vp[j].first - vp[i].first + 1;
                          p={vp[i].first,vp[j].first};
                      }
                    
                  }
                
              }
              j++;
              
          }
        
          return p;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int arr[N][N];
        pair<int,int> rangee;
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
        Solution obj;
	    rangee = obj.findSmallestRange(arr, n, k);
	    cout<<rangee.first<<" "<<rangee.second<<"\n";
    }   
	return 0;
}


// } Driver Code Ends