//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	char data;
	struct Node *left;
	struct Node *right;

	Node(char x) {
		data = x;
		left = NULL;
		right = NULL;
	}
};

struct Node* buildTree(string str)
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
/*The structure of the Binary Tree Node  is
struct Node
{
  char data;
  struct Node* left;
  struct Node* right;
};*/

class Solution {
public:
    // This function returns true if the tree contains a duplicate subtree of size 2 or more; otherwise, it returns false
    void func(Node *root, vector <int> &res) {
        if (!root) return;  // Base case: If the current node is NULL, return
        res.push_back(root->data);  // Store the current node's data in the result vector
        func(root->left, res);  // Recursively traverse the left subtree
        func(root->right, res);  // Recursively traverse the right subtree
    }

    void helper(Node *root, set <vector<int>> &s, bool &ans) {
        if (!root) return;  // Base case: If the current node is NULL, return
        vector <int> res;
        func(root, res);  // Call the 'func' function to gather data from the subtree rooted at 'root'
        if (res.size() > 1) {  // Check if the gathered data forms a subtree of size 2 or more
            if (s.find(res) != s.end()) {  // If the subtree already exists in the set, set 'ans' to true and return
                ans = true;
                return;
            }
            s.insert(res);  // Otherwise, insert the subtree data into the set
        }
        helper(root->left, s, ans);  // Recursively process the left subtree
        helper(root->right, s, ans);  // Recursively process the right subtree
    }

    int dupSub(Node *root) {
        bool ans = false;
        set <vector<int>> s;
        helper(root->left, s, ans);  // Start by processing the left subtree
        helper(root->right, s, ans);  // Then, process the right subtree
        return ans;  // Return the result, indicating whether a duplicate subtree exists
    }
};



//{ Driver Code Starts.

int main()
{
	
	int t;
	cin >> t;
	//cout << t << "\n";
	while (t--)
	{
		string treeString;
		getline(cin >> ws, treeString);
		struct Node* root = buildTree(treeString);
		Solution ob;
		cout << ob.dupSub(root) << "\n";
	}
	return 0;
}
// } Driver Code Ends