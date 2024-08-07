//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
// User function Template for C++

/* Linked List node structure

struct Node {
    int data;
    struct Node *next;
};

*/

class Solution {
  public:
    Node* removeAllDuplicates(struct Node* head) {
        // code here
        Node *dummy=new Node(-1);
        dummy->data=-1;
        dummy->next=head;
        Node *prev=dummy;
        Node *curr=head;
        while(curr!=NULL&&curr->next!=NULL)
        {
            bool dup = false;
            while(curr->next!=NULL&&curr->data==curr->next->data){
                dup=true;
                curr->next=curr->next->next;
            }
            
            if(dup){
                prev->next=curr->next;
                curr=prev->next;
            }
            else{
                if(curr!=NULL)
                    curr=curr->next;
                prev=prev->next;
            }
        }
        head=dummy->next;
        return head;
    }
};

//{ Driver Code Starts.
/* Function to print linked list */
void printList(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

// Driver program to test above functions
int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;

        cin >> N;

        Node *head = NULL;
        Node *temp = head;

        for (int i = 0; i < N; i++) {
            int data;
            cin >> data;
            if (head == NULL)
                head = temp = new Node(data);
            else {
                temp->next = new Node(data);
                temp = temp->next;
            }
        }

        Solution ob;
        head = ob.removeAllDuplicates(head);
        printList(head);

        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends