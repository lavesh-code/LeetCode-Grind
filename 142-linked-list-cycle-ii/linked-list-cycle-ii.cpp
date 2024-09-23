/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


/*
RESOURCES:
LL CYCLE 2: 
https://leetcode.com/problems/linked-list-cycle-ii/description/ 
https://www.youtube.com/watch?v=tsQT0MT73Og&ab_channel=Fraz
striver https://youtu.be/QfbOhn0WZ88?si=bp1vPfzZ9tMvLhQQ
starting point: https://youtu.be/2Kd0KKmmHFc?si=wyj4d2zOoWx6di__
https://www.geeksforgeeks.org/find-first-node-of-loop-in-a-linked-list/

*/ 
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        // the first node i reach twice is my starting node
        unordered_map<ListNode*, bool> visited;
        ListNode* temp = head;

        while (temp != nullptr) {
            if (visited.find(temp) != visited.end()) {
                return temp;
            }
            visited[temp] = true;
            temp = temp->next;
        }
        return nullptr;
    }
};