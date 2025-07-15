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
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        if (head == NULL || head->next == NULL) return true;

        // Step 1: find middle element
        while(fast!=NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast -> next -> next;
        }
        // fast next is null, slow is exactly in middle
        // fast is null, slow is in the starting of second half

        if (fast != NULL && fast->next == NULL) slow = slow->next;

        // Step 2: reverse second half
        ListNode* prev = NULL;
        ListNode* cur = slow;
        ListNode* nxt = NULL;

        while(cur != NULL){
            nxt = cur -> next;
            cur -> next = prev;
            prev = cur;
            cur = nxt;
            //cout<< "reversing";
        }

        // prev is the head 

        // Step 3: Compare first half and reversed second half
        ListNode* first = head;
        ListNode* second = prev;
        while (second != NULL) {
            if (first->val != second->val) return false;
            first = first->next;
            second = second->next;
        }

        return true;

    }
};