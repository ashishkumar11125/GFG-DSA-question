//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};


// } Driver Code Ends
/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump petrol[],int n)
    {
       //Your code here
       int s=0;
       int balance=0, extra=0;
       for(int i=0;i<n;i++){
           balance+=(petrol[i].petrol-petrol[i].distance);
           if(balance<0){
               // this means collapse those distances and add the extra petrol required to complete the tour
               // this also means this starting position of i is not the answer
               s=i+1;
               extra+=balance;
               balance=0;
           }
       }
       return (balance+extra>=0)? s:-1;
    }
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        Solution obj;
        cout<<obj.tour(p,n)<<endl;
    }
}

// } Driver Code Ends