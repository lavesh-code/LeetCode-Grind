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
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL && slow != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;

            if (slow == fast){
                return true;
            }
        }
        return false;
    }

/* Imagine a race where one runner moves at twice the speed of another. The  faster runner covers the ground faster and closes the gap, resulting in a reduction in the distance between them. Similarly, the fast pointer catches up to the slow pointer in the looped linked list, closing in the gap between them until it reaches zero. */

    //     ListNode* slow = head;
    //     ListNode* fast = head;

    //     while(fast != NULL && fast->next !=NULL){
    //         fast = fast->next->next;
    //         slow = slow->next; 

    //         if(fast == slow){
    //             return true;
    //         }
    //     }
        
    //     return false; 
    // }
};