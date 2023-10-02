//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution 
{
public:
bool possible(int n, int k, vector<int> &stalls,int distance){
        int cows=1,coord=stalls[0];
        for(int i=1;i<n;i++){
            if((stalls[i]-coord)>=distance){
                coord=stalls[i];
                cows++;
            }
        }
        return (cows>=k);
    }

    int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
        sort(stalls.begin(),stalls.end());
        int max=stalls[n-1];
        int min=stalls[0];
        int low=1,high=max-min,ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(possible(n,k,stalls,mid) == false){
                high=mid-1;
            }
            else{
                low=mid+1;
                ans=mid;
            }
    }
    return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends