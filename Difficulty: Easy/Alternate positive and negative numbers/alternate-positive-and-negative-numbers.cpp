//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    void rearrange(vector<int> &arr) {
       vector<int>positive;
       vector<int>negative;
       
       for(int i=0;i<arr.size();i++)
       {
           if(arr[i]>=0)
           {
               positive.push_back(arr[i]);
           }
           else
           {
               negative.push_back(arr[i]);
           }
       }
      vector<int>ans;
       
       reverse(positive.begin(),positive.end());
       reverse(negative.begin(),negative.end());
       
       int pos=positive.size()-1;
       int  neg=negative.size()-1;
       
       
       for(int i=0;i<arr.size();i++)
       {
           if(i%2==0 && pos>=0)
           {
               ans.push_back(positive[pos--]);
                 positive.pop_back();
           }
           
           else if(pos<0 && neg>=0)
           {
               ans.push_back(negative[neg--]);
               negative.pop_back();
           }
           else if(pos>=0 && neg<0)
           {
               ans.push_back(positive[pos--]);
               positive.pop_back();
           }
           else if(neg>=0)
           {
               
                 ans.push_back(negative[neg--]);
                 negative.pop_back();
               
           }
           
       }
       
      
       arr=ans;


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
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        ob.rearrange(arr);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends