//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;


// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

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

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/* A binary tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution {
public:
    // Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root) {
        // Call the helper function dfsHeight to determine if the tree is balanced.
        // If the result is not equal to -1, the tree is balanced; otherwise, it's not.
        return dfsHeight(root) != -1;
    }
    
    // Helper function to calculate the height of the binary tree rooted at 'root'.
    int dfsHeight(Node* root) {
        // Base case: If the root is NULL (empty tree), the height is 0.
        if (root == NULL) return 0;
        
        // Recursively calculate the height of the left subtree.
        int leftHeight = dfsHeight(root->left);
        
        // If the left subtree is unbalanced, propagate the unbalanced status (-1).
        if (leftHeight == -1) return -1;
        
        // Recursively calculate the height of the right subtree.
        int rightHeight = dfsHeight(root->right);
        
        // If the right subtree is unbalanced, propagate the unbalanced status (-1).
        if (rightHeight == -1) return -1;
        
        // If the absolute difference between the heights of left and right subtrees
        // is greater than 1, the tree is unbalanced, so propagate -1 to indicate that.
        if (abs(leftHeight - rightHeight) > 1) return -1;
        
        // Return the height of the current node, which is 1 plus the maximum height
        // between the left and right subtrees. This ensures that the height returned
        // from this node is the height of the subtree rooted at this node.
        return 1 + max(leftHeight, rightHeight);
    }
};



//{ Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);
        Solution ob;
        cout << ob.isBalanced(root) << endl;
    }
    return 0;
}

// } Driver Code Ends