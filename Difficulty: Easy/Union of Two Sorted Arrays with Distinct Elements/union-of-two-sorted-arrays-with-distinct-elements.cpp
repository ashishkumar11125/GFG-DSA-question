//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // a,b : the arrays
    // Function to return a list containing the union of the two arrays.
     vector<int> findUnion(vector<int> &a, vector<int> &b) {
        vector<int>v;
        int n1=a.size();
        int n2=b.size();
        int i=0,j=0;
   int maxi=0;
   for(int i=0;i<n1;i++){
        maxi=max(maxi,a[i]);
    }
    for(int i=0;i<n2;i++){
        maxi=max(maxi,b[i]);
    }
        int  hash[maxi+1]={0};
        for(int i=0;i<n1;i++){
        hash[a[i]]++;
    }
    for(int i=0;i<n2;i++){
        hash[b[i]]++;
    }
    for(int i=0;i<=maxi;i++){
        if(hash[i]>0){
            v.push_back(i);
        }
    }
    return v;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a, b;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        // Read second array
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            b.push_back(number);
        }

        Solution ob;
        vector<int> ans = ob.findUnion(a, b);
        for (int i : ans)
            cout << i << ' ';
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends