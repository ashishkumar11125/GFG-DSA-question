/* structure for a node
class Node {
 public:
  int data;
  Node *next;

  Node(int x){
      data = x;
      next = NULL;
  }
}; */

class Solution {
  public:
    Node* sortedInsert(Node* head, int data) {
        // code here
        Node* prev = head;
        Node* nex = head;
        while(prev -> next != head) prev = prev -> next;
        if(data <= head -> data || data >= prev -> data) {
            prev -> next = new Node(data);
            prev -> next -> next = head;
            if(data <= head -> data) return prev -> next;
            return head;
        }
        while(nex -> data < data) {
            prev = nex;
            nex = nex -> next;
        }
        prev -> next = new Node(data);
        prev -> next -> next = nex;
        return head;
    }
};