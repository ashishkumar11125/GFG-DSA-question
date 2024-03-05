//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        vector <int> search(string pattern, string text)
        {
            //code here.
            vector<int> ans;
            for(int i=0;i<=text.size()-pattern.size();i++)
            {
                if(pattern[0]==text[i])
                {
                    int j=0,k=i;
                    ans.push_back(k+1);
                    while(k<text.size() and j<pattern.size() and text[k]==pattern[j])k++,j++;
                    if(j!=pattern.size())ans.pop_back();
                }
            }
            return ans;
        }
     
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends