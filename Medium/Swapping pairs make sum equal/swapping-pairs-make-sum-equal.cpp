//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
    int findSwapValues(int a[], int n, int b[], int m) {
        // Your code goes here
        set<int> arr1;  int sum1=0; 
     set<int> arr2; int sum2=0;
    

// save sum1 && sum2


     for(int i=0;i<n;i++)
     { 
         sum1=sum1+a[i];
         arr1.insert(a[i]);
     }
     
     for(int i=0;i<m;i++)
     { sum2=sum2+b[i];
         arr2.insert(b[i]);
     }
     

 

 // only  unique element should be exchange
     for(auto i:arr1)
     {
      
        
       

          for(auto j:arr2 )
         {
            if((sum2-j+i)==(sum1-i+j))
            {
                return 1;
            }
             
             
         }
     }
     
     
     return -1;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n];
        int b[m];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];

        Solution ob;
        cout << ob.findSwapValues(a, n, b, m);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends