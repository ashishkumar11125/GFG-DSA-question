//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	vector<int> generateNextPalindrome(int num[], int n)
{
    // first replace the value, with change variable
    // if change variable true, that means i need to change one time value
    // by carry > 0
 
    bool change = true;
    int left = 0, right = n - 1;
    while (left < right)
    {
        if (num[left] < num[right])
            change = true; // it means curr time my number is less than, so mark change true
        else if (num[left] > num[right])
            change = false; // it means curr time my number is greater than, so mark change to false, we don't need to update further
        
        num[right] = num[left];
        left++, right--;
    }
 
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
        ans[i] = num[i];
 
    int ind = n / 2; // work for both even and odd case
    bool carry = change;
    while (carry && ind < n)
    {
        if (ans[ind] == 9)
        {
            ans[ind] = 0;
            ans[n - 1 - ind] = 0;
        }
        else
        {
            ans[ind]++;
            ans[n - 1 - ind] = ans[ind];
            carry = 0;
        }
 
        ind++;
    }
 
    if (carry)
    {
        ans[0] = 1;
        ans.push_back(1);
    }
 
    return ans;
	}

};

//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int num[n];
        for (int i = 0; i < n; i++) {
            cin >> num[i];
        }
        Solution ob;
        auto ans = ob.generateNextPalindrome(num, n);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends