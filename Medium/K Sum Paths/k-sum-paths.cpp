//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node 
{
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) 
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function template for C++

/*
struct Node 
{
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
public:
    // Helper function to perform the recursive traversal and count the paths with sum k
    void helper(Node* root, int k, int prev, int &ans, unordered_map<int, int> &mp) {
        if (root == NULL) {
            return;
        }

        int curr = prev + root->data; // Calculate the cumulative sum up to the current node

        // Check if there exists a cumulative sum (curr - k) in the map, and update the answer
        if (mp.find(curr - k) != mp.end()) {
            ans += mp[curr - k];
        }

        // If the current cumulative sum is equal to k, increment the answer
        if (curr == k) {
            ans++;
        }

        mp[curr]++; // Update the map with the current cumulative sum

        // Recursively traverse the left and right subtrees
        helper(root->left, k, curr, ans, mp);
        helper(root->right, k, curr, ans, mp);

        mp[curr]--; // Backtrack: Remove the current cumulative sum from the map
    }

    // Function to find the number of paths in a binary tree with a given sum k
    int sumK(Node* root, int k) {
        int ans = 0; // Initialize the answer variable
        unordered_map<int, int> mp; // Map to store cumulative sums and their frequencies
        helper(root, k, 0, ans, mp); // Call the helper function to perform the traversal
        return ans; // Return the final answer
    }
};


//{ Driver Code Starts.

int main() {
    string tc;
    getline(cin, tc);
    int t = stoi(tc);
  
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);

        string key;
        getline(cin, key);
        int k=stoi(key);
        Solution ob;
        cout << ob.sumK(root, k) << "\n";
    }
    return 0;
}
// } Driver Code Ends