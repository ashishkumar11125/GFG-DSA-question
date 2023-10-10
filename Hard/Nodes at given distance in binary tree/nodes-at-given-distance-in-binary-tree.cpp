//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

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
    Node* root = newNode(stoi(ip[0]));
        
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
            currNode->left = newNode(stoi(currVal));
                
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
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends
/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

class Solution{
    
private:

    // This unordered_map stores the parent nodes of each node.
    unordered_map<Node*,Node*> p;
    
    // This unordered_map is used to mark nodes as visited during traversal.
    unordered_map<Node*,int> vis;
    
    // The targetNode will store the node with the target value.
    Node *targetNode;
    
    // Helper function to configure the parent relationships of nodes.
    void configureParents(Node* node, int target){
        // If the current node's data matches the target value and targetNode is not set, assign the current node to targetNode.
        if(node->data == target && targetNode == NULL)
            targetNode = node;
        
        // Recursively configure the parent-child relationship for the left and right subtrees.
        if(node->left) p[node->left] = node, configureParents(node->left, target);
        if(node->right) p[node->right] = node, configureParents(node->right, target);
    }
    
    // Helper function for depth-first search to find nodes at distance k from the targetNode.
    void dfs(Node* node, int k, vector<int> &nodes){
        // Mark the current node as visited.
        vis[node] = 1;
        
        // If k reaches 0, add the current node's data to the result vector.
        if(k == 0){
            nodes.push_back(node->data);
            return;
        }
        
        // Recursively explore the left, right, and parent nodes (if they exist and haven't been visited).
        if(node->left && !vis[node->left]) dfs(node->left, k - 1, nodes);
        if(node->right && !vis[node->right]) dfs(node->right, k - 1, nodes);
        if(p[node] && !vis[p[node]]) dfs(p[node], k - 1, nodes);
    }
    
public:

    // Main function to find nodes at distance k from the targetNode.
    vector <int> KDistanceNodes(Node* root, int target, int k){
        // Clear data structures before starting the search.
        p.clear();
        vis.clear();
        p[root] = targetNode = NULL;
        
        // Configure parent relationships and find the targetNode.
        configureParents(root, target);
        
        // Vector to store the nodes at distance k.
        vector<int> nodes;
        
        // Perform DFS to find nodes at distance k from targetNode.
        dfs(targetNode, k, nodes);
        
        // Sort the result vector in ascending order.
        sort(nodes.begin(), nodes.end());
        
        return nodes;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    
    Solution x = Solution();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* head = buildTree(s);
        
        int target, k;
        cin>> target >> k;
        getchar();
        
        vector <int> res = x.KDistanceNodes(head, target, k);
        
        for( int i=0; i<res.size(); i++ )
            cout<< res[i] << " ";
        cout<<endl;
    }
    return 0;
}

// } Driver Code Ends