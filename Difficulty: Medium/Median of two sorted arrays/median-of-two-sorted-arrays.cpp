//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

//Position this line where user code will be pasted.
class Solution {
  public:
    int SumofMiddleElements(vector<int> &arr1, vector<int> &arr2) {
        // code here
        vector<int>sol;
        
        int index1 = 0 ;
        int index2 = 0;
        int n1 = arr1.size(), n2 = arr2.size();
        
        while(index1<n1 && index2<n2){
            
            if(arr1[index1]<= arr2[index2]){
                sol.push_back(arr1[index1]);
                index1++;
            }else {
                sol.push_back(arr2[index2]);
                index2++;
            }
        }
        
        while(index1<n1){
            sol.push_back(arr1[index1]);
            index1++;
        }
        while(index2<n2){
            sol.push_back(arr2[index2]);
            index2++;
        }
        int size = sol.size();
        if(size%2 == 0){
            return sol[size/2] + sol[size/2 -1];
        }
        
        return sol[size/2];
    }
};

//{ Driver Code Starts.
//Back-end complete function template in C++

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr, brr;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1) {
            arr.push_back(number1);
        }
        string input2;
        getline(cin, input2);
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2) {
            brr.push_back(number2);
        }
        Solution ob;
        int res = ob.SumofMiddleElements(arr, brr);
        cout << res << endl;
    }
}
// } Driver Code Ends