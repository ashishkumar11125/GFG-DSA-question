//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


// } Driver Code Ends
/*Structure of the Node of the BST is as
struct Node
{
	int data;
	Node* left, *right;
};
*/

class Solution
{
public:
    // Your are required to complete this function
    // function should return the root of the modified BST

    // Helper function to perform an in-order traversal and store nodes in a vector.
    void inorder(Node *root, vector<Node *>& v)
    {
        if (root != NULL)
        {
            // Visit the left subtree
            inorder(root->left, v);
            
            // Add the current node to the vector
            v.push_back(root);
            
            // Visit the right subtree
            inorder(root->right, v);
        }
    }

    // Helper function to construct a balanced BST from a sorted vector of nodes.
    Node* construct(vector<Node *>& v, int start, int end)
    {
        if (start > end)
            return NULL;
        
        // Calculate the middle index
        int mid = (start + end) / 2;
        
        // Get the node at the middle index
        Node *temp = v[mid];
        
        // Recursively build the left and right subtrees
        temp->left = construct(v, start, mid - 1);
        temp->right = construct(v, mid + 1, end);
        
        return temp;
    }

    Node* buildBalancedTree(Node* root)
    {
        // Code here

        // Create a vector to store nodes in sorted order
        vector<Node *> v;
        
        // Perform an in-order traversal to populate the vector
        inorder(root, v);

        int start = 0;
        int end = v.size();

        // Construct a balanced BST from the sorted vector
        return construct(v, start, end - 1);
    }
};



//{ Driver Code Starts.

Node* insert(struct Node* node, int key){
	if (node == NULL) return new Node(key);
	if (key < node->data)
		node->left = insert(node->left, key);
	else if (key > node->data)
		node->right = insert(node->right, key);
	return node;
}

void preOrder(Node* node)
{
	if (node == NULL)return;
	printf("%d ", node->data);
	preOrder(node->left);
	preOrder(node->right);
}

int height(struct Node* node) 
{
  if (node==NULL) 
    return 0;
  int lDepth = height(node->left);
  int rDepth = height(node->right);
  if (lDepth > rDepth) 
    return(lDepth+1);
  else 
    return(rDepth+1);
} 
Node *buildTree(string str) {
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

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
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

Node* buildBalancedTree(Node* root);

int main()
{
    int t;
    cin>>t;
    getchar();
    while(t--)
    {
        struct Node *root = NULL;
        int n, temp;
        string tree;
        getline(cin,tree);
        root = buildTree(tree);
        // cout<<height(root)<<endl;
        Solution obj;
        root = obj.buildBalancedTree(root);
        cout<<height(root)<<endl;
    }
	return 0;
}

// } Driver Code Ends