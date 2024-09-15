//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node()
        : data(0)
        , left(NULL)
        , right(NULL) {}

    Node(int x)
        : data(x)
        , left(NULL)
        , right(NULL) {}
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node(val);
    return temp;
}

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input string after splitting by space
    vector<string> ip;
    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {
        Node* currNode = queue.front();
        queue.pop();
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {
            currNode->left = newNode(stoi(currVal));
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {
            currNode->right = newNode(stoi(currVal));
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

/* Function to print nodes in a given doubly linked list */
void printList(Node* node) {
    Node* prev = NULL;
    while (node != NULL) {
        cout << node->data << " ";
        prev = node;
        node = node->right;
    }
    cout << endl;
    while (prev != NULL) {
        cout << prev->data << " ";
        prev = prev->left;
    }
    cout << endl;
}

void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data;
        inorder(root->right);
    }
}


// } Driver Code Ends
/* Structure for tree and linked list

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

// This function should return head to the DLL
class Solution {
  public:
    vector<int> res;  // Result vector to store in-order traversal of the tree
    
    // Recursively traverse the binary tree in in-order fashion
    void rec(Node* root) {
        // Agar root NULL hai toh kuch nahi karna (base case)
        if (root == NULL) return;
        
        // Left subtree ko traverse karo
        rec(root->left);
        
        // Current node ka data result vector mein add karo
        res.push_back(root->data);
        
        // Right subtree ko traverse karo
        rec(root->right);
    }
    
    // Function to convert Binary Tree to Doubly Linked List (DLL)
    Node* bToDLL(Node* root) {
        // Ek dummy head node banate hain jo -1 value ka hoga
        Node* head = new Node(-1);
        
        // Binary tree ka in-order traversal karke result vector mein store karo
        rec(root);
        
        // Pointers to maintain previous node and current temp node
        Node* prev = NULL; 
        Node* temp = head;
        
        // In-order traversal ke nodes ko DLL mein convert karo
        for (auto i : res) {
            // Nayi node create karo aur usko temp ke right mein add karo
            temp->right = new Node(i);
            // Temp ka left pointer previous node ko point karega
            temp->left = prev;
            // Previous node ko update karo
            prev = temp;
            // Temp pointer ko next node par shift karo
            temp = temp->right;
        } 
        // Last node ka left pointer previous node ko point karega
        temp->left = prev;
        
        // Head ke right wale node ko return karo (jo actual DLL ka head hoga)
        Node* ans = head->right;
        ans->left = NULL;  // Head node ke left ko NULL set karo
        return ans;  // DLL ka head return karo
    }
};


//{ Driver Code Starts.

/* Driver program to test size function */
int main() {
    int t;
    cin >> t;
    getchar();

    while (t--) {
        string inp;
        getline(cin, inp);
        Node* root = buildTree(inp);

        Solution ob;
        Node* head = ob.bToDLL(root);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends