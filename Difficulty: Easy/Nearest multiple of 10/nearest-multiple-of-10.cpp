//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string roundToNearest(string str) {
        // Complete the function
        int n = str.size();
        
        // base case
        if(str[n-1] == '0') 
            return str;
            
        // 0 < last digit < 6
        else if('0' < str[n-1] && str[n-1] < '6'){
            str.pop_back();
            str.push_back('0');
            return str;
        }
        
        // else, 5 < last digit <= 9
        str.pop_back();
        str.push_back('0');
        int i = n-2;
        while(str[i]=='9' && i>=0){
            str[i] = '0';
            i--;
        }
        // if all are '9' ex. 99997
        if(i<0){ 
            return '1'+str;
        }    
        
        else{ // like example: 1239998
            str[i] = (str[i]+1);
        }
        
        return str;        
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.roundToNearest(str) << endl;
    }

    return 0;
}
// } Driver Code Ends