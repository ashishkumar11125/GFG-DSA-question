//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string doIntersect(int p1[], int q1[], int p2[], int q2[]) {
        // code here
        double slope_1 = (double)(q1[1] - p1[1]) / (double)(q1[0] - p1[0]);
        double slope_2 = (double)(q2[1] - p2[1]) / (double)(q2[0] - p2[0]);
        if(slope_1 == slope_2){
            return "false";
        }
        bool check_211 = p2[1]-p1[1] - slope_1*(p2[0]-p1[0]) >0?true:false;
        bool check_212 = q2[1]-p1[1] - slope_1*(q2[0]-p1[0]) >0?true:false;
        bool check_121 = p1[1]-p2[1] - slope_2*(p1[0]-p2[0]) >0?true:false;
        bool check_122 = q1[1]-p2[1] - slope_2*(q1[0]-p2[0]) >0?true:false;
        if((check_211==true && check_212 == true) || (check_211==false && check_212 == false) || 
        (check_121 == true && check_122 == true) || (check_121 == false && check_122 == false))
        {
            return "false";
        }
        return "true";
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int p1[2], q1[2], p2[2], q2[2];
        cin >> p1[0] >> p1[1] >> q1[0] >> q1[1] >> p2[0] >> p2[1] >> q2[0] >> q2[1];
        // if (q2[1] == -2) {
        //     cout << "true" << endl;
        //     return 0;
        // }
        Solution ob;
        // int a = ob.doIntersect(p1, q1, p2, q2);
        // if (a)
        cout << ob.doIntersect(p1, q1, p2, q2) << "\n";
    }
}
// } Driver Code Ends