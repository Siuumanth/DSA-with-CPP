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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL)  return nullptr;
        ListNode* cur = head;
        int n = 0;

        // 1. find total length of LL
        while(cur->next != NULL){
            n++;
            cur = cur->next;
        }
        n++;
        k = k%n;

        // Step 2: Make it circular
        cur->next = head;

        int c = 0;
        cur = head;     // n = 5, k = 2, n-k-1 = 2

        // Step 3: Find new head after (n - k) steps
        while(c < n-k-1){
            cur = cur->next;
            c++;
        }

        // 4. Breaking the chain
        ListNode* temp = cur->next;
        cur->next = NULL;

        return temp;
    }
};