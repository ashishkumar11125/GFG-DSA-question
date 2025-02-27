//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    stack<pair<int,int>>st;
    int mini=INT_MAX;
    Solution() {}
    void push(int x) {
        mini=min(mini,x);
        st.push({x,mini});
    }
    //each element in the stack stores {value, min_so_far}
    void pop() {
        if(st.empty())  return;
        st.pop();
        if(st.empty())
            mini=INT_MAX;
        else
            mini=st.top().second;
    }

    int peek() {
        if(st.empty())  return -1;
        return st.top().first;
    }
    int getMin() {
        if(st.empty())  return -1;
        return st.top().second;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int q;
        cin >> q;

        Solution ob;

        while (q--) {
            int qt;
            cin >> qt;

            if (qt == 1) {
                // push
                int att;
                cin >> att;
                ob.push(att);
            } else if (qt == 2) {
                // pop
                ob.pop();
            } else if (qt == 3) {
                // peek
                cout << ob.peek() << " ";
            } else if (qt == 4) {
                // getMin
                cout << ob.getMin() << " ";
            }
        }
        cout << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends