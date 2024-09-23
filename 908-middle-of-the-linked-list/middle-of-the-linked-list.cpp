/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* temp1 = head;
        ListNode* temp2 = head;

        // Move temp2 two steps and temp1 one step until temp2 reaches the end
        // check null condition always
        while (temp2 != NULL && temp2->next != NULL) {
            temp2 = temp2->next->next;
            temp1 = temp1->next;
        }

        return temp1;
    }
};