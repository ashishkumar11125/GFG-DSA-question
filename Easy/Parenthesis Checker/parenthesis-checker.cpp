//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        stack<char> stack_ele;
    for (char ch : x) {
            if (ch == '(' || ch == '{' || ch == '[') {
                stack_ele.push(ch);
            } else {
                if (stack_ele.empty()) {
                    return false;
                } else if ((stack_ele.top() == '(' && ch == ')') || (stack_ele.top() == '{' && ch == '}') || (stack_ele.top() == '[' && ch == ']')) {
                    stack_ele.pop();
                } else {
                    return false;
                }
            }
        }
        return stack_ele.empty();
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends