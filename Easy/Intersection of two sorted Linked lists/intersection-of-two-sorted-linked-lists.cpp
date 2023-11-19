//{ Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

Node* inputList(int size)
{
    Node *head, *tail;
    int val;
    
    cin>>val;
    head = tail = new Node(val);
    
    while(--size)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    if(n)
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    else cout<< " ";
}


// } Driver Code Ends
/* The structure of the Linked list Node is as follows:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

class Solution {
public:
    // Function to find the intersection of two sorted linked lists
    Node* findIntersection(Node* head1, Node* head2) {
        // code goes here
        // Create a dummy node to store the result
        Node* dummy = new Node(-1);
        Node* ans = dummy; // Pointer to the current node in the result list
        Node* temp1 = head1; // Pointer to traverse the first list
        Node* temp2 = head2; // Pointer to traverse the second list

        // Traverse both lists until one of them reaches the end
        while (temp1 && temp2) {
            // If the data in both nodes is equal, add the node to the result list
            if (temp1->data == temp2->data) {
                ans->next = new Node(temp1->data); // Create a new node with the common data
                ans = ans->next; // Move the pointer to the last added node in the result list
                temp1 = temp1->next; // Move to the next node in the first list
                temp2 = temp2->next; // Move to the next node in the second list
            }
            // If the data in the first list is greater, move to the next node in the second list
            else if (temp1->data > temp2->data) {
                temp2 = temp2->next;
            }
            // If the data in the second list is greater, move to the next node in the first list
            else if (temp2->data > temp1->data) {
                temp1 = temp1->next;
            }
        }

        return dummy->next; // Return the head of the result list (skipping the dummy node)
    }
};



//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    cin>> n >> m;
	    
	    Node* head1 = inputList(n);
	    Node* head2 = inputList(m);
	    
	    Solution ob;
	    Node* result = ob.findIntersection(head1, head2);
	    
	    printList(result);
	    cout<< endl;
	}
	return 0;
}

// } Driver Code Ends