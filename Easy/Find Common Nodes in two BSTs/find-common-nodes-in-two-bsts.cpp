//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
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


class Solution {
public:
    // In-order traversal of a BST, storing values in vector v.
    void io(Node *root, vector<int> &v) {
        if (root != NULL) {
            io(root->left, v);     // Traverse left subtree.
            v.push_back(root->data); // Add current node's value to the vector.
            io(root->right, v);    // Traverse right subtree.
        }
    }

    // Function to find common nodes in two BSTs.
    vector<int> findCommon(Node *root1, Node *root2) {
        vector<int> v1, v2; // Vectors to store in-order traversal results.
        io(root1, v1);      // Perform in-order traversal on the first BST.
        io(root2, v2);      // Perform in-order traversal on the second BST.
        
        map<int, int> mp;   // Map to count occurrences of values in v1.

        // Count occurrences of values from v1 in the map.
        for (int i = 0; i < v1.size(); i++) {
            mp[v1[i]]++;
        }

        vector<int> ans;    // Vector to store common elements.

        // Check for common elements from v2 in the map.
        for (int i = 0; i < v2.size(); i++) {
            if (mp[v2[i]]) {
                ans.push_back(v2[i]);
            }
        }
        return ans;
    }
};





//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root1 = buildTree(s);

        getline(cin,s);
        Node* root2 = buildTree(s);
        Solution ob;
        vector <int> res = ob.findCommon(root1, root2);
        for (int i : res)
            cout << i << " ";
        cout<< endl;
    }

	return 1;
}
// } Driver Code Ends