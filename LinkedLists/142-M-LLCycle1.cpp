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
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        bool isCycle = false;

        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){
                isCycle = true;
                break;
            }
        }

        if(!isCycle) return NULL; // No cycle present

        slow = head; // make slow as head again and then increment slow and fast by 1 

        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        } 

        return slow;
        

    }
};