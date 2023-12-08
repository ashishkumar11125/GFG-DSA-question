//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


// siddhat se karna ho jayega bs ek hi mauka hai 
// phale prme function nikal lo phr toh bs jodna ghatana hai 
// baki koi dikkar hai toh tmhara bhai hai naa
 


vector<bool> sieve;
class Solution
{
    public:
    void fun(){
        sieve.resize(1e6+5,true);
        sieve[0]=sieve[1]=false;
        for(long i=2;i*i<=1e6+5;i++){
            if(!sieve[i]) continue;
            for(int j=i+i;j<1e6+5;j+=i){
                sieve[j]=false;
            }
        }
    }
    
    int minNumber(int arr[],int n)
    {
        if(sieve.empty()) fun();
        int sum=accumulate(arr,arr+n,0);
        int i=0;
        while(!sieve[sum]){
            sum++,i++;
        }
        return i;
    }
};




//{ Driver Code Starts.

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution obj;
        cout << obj.minNumber(arr, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends