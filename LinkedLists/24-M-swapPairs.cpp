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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;

        ListNode* first = head;    // first and second 
        ListNode* second = head->next;

        ListNode* prev = new ListNode();   // stack allocation for prev
        prev->next = head; 
        head = second; // new head

        while(first != NULL && second != NULL){
            first->next = second->next;   // swapping 
            second->next = first;
            prev->next = second;

            // move forward
            prev = first;    // saving prev node here
            first = first->next;
            if(first != NULL) second = first->next;
        } 

        return head;
        
    }
};