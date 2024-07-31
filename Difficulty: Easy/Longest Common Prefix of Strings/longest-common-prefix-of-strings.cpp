//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:

    string longestCommonPrefix(vector<string> arr) {
        // your code here
         string smin = *min_element(arr.begin(), arr.end(), 
                     [] (const string& s1, const string& s2) { 
                         return s1.length() < s2.length(); }
                     );
                     
        string str= "";
        
        for(int i=0; i<smin.size(); i++){
            char ch = smin[i];

            for(int j=0; j<arr.size(); j++){
                string temp = arr[j];

                if(ch == temp[i])
                    continue;
                else{
                    if(str == "") return "-1";
                    else return str;
                }
            }
            
            str += ch;
        }
        return str;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.longestCommonPrefix(arr) << endl;
    }
}

// } Driver Code Ends