//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
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

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*Structure of the Node of the BST is as
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
private:
    // Helper function to perform inorder traversal of a binary tree and store elements in a vector.
    void inorder(Node* root, vector<int>& ans) {
        if (root == NULL) {
            return;
        }

        inorder(root->left, ans);
        ans.push_back(root->data);
        inorder(root->right, ans);
    }

public:
    // Function to count pairs from two BSTs whose sum is equal to a given value (x).
    int countPairs(Node* root1, Node* root2, int x) {
        // Vector to store elements of the first BST.
        vector<int> vec1;
        inorder(root1, vec1);

        // Vector to store elements of the second BST.
        vector<int> vec2;
        inorder(root2, vec2);

        // Initialize pointers for two-pointer approach.
        int i = 0;
        int j = vec2.size() - 1;
        
        // Initialize count of pairs.
        int count = 0;

        // Two-pointer approach to find pairs with the given sum.
        while (i < vec1.size() && j >= 0) {
            int sum = vec1[i] + vec2[j];
            if (sum == x) {
                count++;
                i++;
                j--;
            } else if (sum < x) {
                i++;
            } else {
                j--;
            }
        }

        return count;
    }
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        string tree1, tree2;
        getline(cin, tree1);
        getline(cin, tree2);
        Node* root1 = buildTree(tree1);
        Node* root2 = buildTree(tree2);
        int x;
        cin >> x;
        cin.ignore();
        Solution ob;
        cout << ob.countPairs(root1, root2, x) << "\n";
    }
    return 0;
}

// } Driver Code Ends