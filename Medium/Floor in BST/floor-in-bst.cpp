//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *right;
    Node *left;

    Node(int x) {
        data = x;
        right = NULL;
        left = NULL;
    }
};


// } Driver Code Ends
// Function to search a node in BST.
class Solution {
public:
    int floor(Node* root, int x) 
    { 
        //code here
        // Check if the tree is empty
        if (root == nullptr) return -1; // No floor value exists in an empty tree

        int ash = -1; // Initialize the result variable to -1, which will store the floor value

        // Traverse the binary search tree to find the floor value of 'x'
        while (root) 
        {
            if (x == root->data)
            {
                // If the current node's data is equal to 'x', 'x' itself is the floor value
                return root->data;
            } 
            else if (x < root->data) 
            {
                // If 'x' is less than the current node's data, move to the left subtree
                root = root->left;
            }
            else
            {
                // If 'x' is greater than the current node's data, update 'ash' and move to the right subtree
                ash = root->data;
                root = root->right;
            }
        }

        // When the loop ends, 'ash' will hold the floor value of 'x'
        return ash;
    }
};


//{ Driver Code Starts.

Node *insert(Node *tree, int val) {
    Node *temp = NULL;
    if (tree == NULL) return new Node(val);

    if (val < tree->data) {
        tree->left = insert(tree->left, val);
    } else if (val > tree->data) {
        tree->right = insert(tree->right, val);
    }

    return tree;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        Node *root = NULL;

        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int k;
            cin >> k;
            root = insert(root, k);
        }

        int s;
        cin >> s;
        Solution obj;
        cout << obj.floor(root, s) << "\n";
    }
}

// } Driver Code Ends