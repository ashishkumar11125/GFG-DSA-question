//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
     //function to calculate sum of digits of prime
    int sumOfPrime(int n)
    {
        int sum=0;
        int temp=n;
        for(int i=2;i*i<=n;i++)
        {
            if(!(n%i))
            {   
                while(n%i==0)
                {
                    n/=i;
                    
                    int fct=i;
                    while(fct)
                    {
                        sum+=fct%10;
                        fct/=10;
                    }
                }
            }
        }
        
        if(n==temp)
        return sum;
        
        if(n>1)
        {
            while(n)
            {
                sum+=n%10;
                n/=10;
            }
        }
        
        return sum;
    }
    
    //function to calculate sum of digits
    int sumOfDigit(int n)
    {
        int sum=0;
        while(n)
        {
            sum+=n%10;
            n/=10;
        }
        return sum;
    }
    
    int smithNum(int n) {
        
        int sum1=sumOfPrime(n);
        int sum2=sumOfDigit(n);
    
    
        if(sum1==sum2)
        return 1;
        else
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;

        Solution ob;
        cout << ob.smithNum(n) << endl;
    }
    return 0;
}
// } Driver Code Ends