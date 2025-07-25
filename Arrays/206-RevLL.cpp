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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* cur = head;
        ListNode* nxt = nullptr; 

        if(head==nullptr) return nullptr;
    
        while(cur->next != nullptr){
            nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        cur->next = prev;
        return cur;
    }
};


