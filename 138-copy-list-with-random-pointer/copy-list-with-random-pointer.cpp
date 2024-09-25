/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
private:
    void insertcopy(Node* head){
        Node* temp = head;
        while(temp != NULL){
            Node* nextelement = temp->next;
            Node* copy = new Node(temp -> val);

            copy ->next = nextelement;
            temp -> next = copy;

            temp = nextelement;
        }
    }
    void connectrandom(Node* head){
        Node* temp = head;
        while(temp != NULL){
            Node* copynode = temp -> next;
            if(temp -> random){
                copynode-> random = temp->random->next;
            }
            else{
                copynode->random = nullptr;
            }
            temp = temp->next->next;
        }
    }
   Node* getdeepcopy(Node* head){
    Node* temp = head;
    Node* dummyNode = new Node(-1);
    Node* res = dummyNode;
    while(temp!= NULL){
        //creating new list
        res->next = temp->next;
        res = res->next;

        //diconnecting and going back to the initial state of ll
        temp ->next = temp->next->next;
        temp = temp->next;
    }
    return dummyNode->next;
   }     
public:
    Node* copyRandomList(Node* head) {
        //step 1-inset copy nodes in between
        insertcopy(head);
        //step 2-connect random pointers to copy nodes
        connectrandom(head);
        //step 3-connect next pointer
        return getdeepcopy(head);
        
    }
};