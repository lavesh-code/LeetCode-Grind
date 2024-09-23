/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


class Solution {
public:
    bool hasCycle(ListNode *head) {

        // min. one node where we START and reach BACK
        // visited a node more than once

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next !=NULL){
            fast = fast->next->next;
            slow = slow->next; 

            if(fast == slow){
                return true;
            }
        }
        
        return false; 
    }
};