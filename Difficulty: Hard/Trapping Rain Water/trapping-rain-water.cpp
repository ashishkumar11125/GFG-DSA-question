//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int n=arr.size();
        int ans=0;
        int i=0;
        int j=1;
        int temp=0;
        while(j<n){
            if(arr[j]>=arr[i]){
                ans+=(arr[i]*(j-i-1));
                ans-=temp;
                temp=0;
                i=j;
            }else{
                temp+=arr[j];
            }
            j++;
        }
        //cout<<ans<<endl;
        
        i=n-1;
        j=n-2;
        temp=0;
        while(j>=0){
            if(arr[j]>arr[i]){ // to avoid double counting 
            // as if we put arr[j]>=arr[i] , then we will double count when arr[i]=arr[j]
            // as it will be true for both pass.
                ans+=(arr[i]*(i-j-1));
                ans-=temp;
                temp=0;
                i=j;
            }else{
                temp+=arr[j];
            }
            j--;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxWater(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends