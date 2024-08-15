//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data % 10;
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
// User function template for C++

/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    Node*reverse(Node*head){
      
      if(head==NULL){
          return head;
      }
      
       Node*prev=NULL;
        Node*curr=head;
        Node*next;
        
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
           
        }
        return prev;
      
  }
    Node* addOne(Node* head) {
        // Your Code here
        // return head of list after adding one
        Node*curr=reverse(head);
        Node*temp=curr;
        int value=0;
        int carry=0;
         curr->data=curr->data+1;
        while(curr!=NULL){
            
              carry=(curr->data)/10;
             value=(curr->data)%10;
              curr->data=value;
                 if(carry!=0&&curr->next!=NULL){
                  curr=curr->next;
                 curr->data=curr->data+carry;
            }else if(carry!=0&&curr->next==NULL){
                Node*new_Node=new Node(carry);
                curr->next=new_Node;
                curr=new_Node;
                carry=0;
            }else{
                curr=curr->next;
            }

        }
        
        return reverse(temp);
       
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends