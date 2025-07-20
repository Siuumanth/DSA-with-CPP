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

    ListNode* reverseHelper(ListNode* start, ListNode* end){
        ListNode* nxt = NULL;
        ListNode* prev = NULL;
        ListNode* cur = start->next;  // initialising for reversing
         // start of the unmodified part is ending of the reversed part
        ListNode* last = start->next; 

        // start(s) -> 1 -> 2 -> 3 -> 4(e)
        // start(s) <- 1 <- 2 <- 3 <- 4(e)
        // point start to 3, and 1 to end
        // start    -> 3 -> 2 -> 1(s) -> 4(e)

        // Reverse:  1 <- 2 <- 3, point start to 3, and 1 to end 

        // reverse like normal 
        while(cur != end){
            nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }

        last->next = end;  // completing the chain
        return prev;   // prev has the 1st node of reversed list
    }


    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head->next == NULL) return head;

        ListNode* dummy = new ListNode();
        dummy->next = head;   // heap allocation, can use stack alloc 

        ListNode* start = dummy;
        ListNode* end = head;
        int c = 0;   // counter to track nodes
        ListNode* newStart;

        while(end != NULL){
            end = end->next;
            c++;
            if(c == k){
                newStart = start->next;  // save start -> next
                // change the chain of the start
                start->next = reverseHelper(start, end);
                start = newStart;
                c = 0; 
            }
        }
        return dummy->next;    // return next of dummy
    }
};



/*
My initial approach

    ListNode* reverseHelper(ListNode* start, ListNode* end){
        ListNode* nxt = NULL;
        ListNode* prev = NULL;
        ListNode* cur = start->next;  // initialising for reversing
         // start of the unmodified part is ending of the reversed part
        ListNode* last = start->next; 

        // start(s) -> 1 -> 2 -> 3 -> 4(e)
        // start(s) <- 1 <- 2 <- 3 <- 4(e)
        // point start to 3, and 1 to end
        // start    -> 3 -> 2 -> 1(s) -> 4(e)

        // Reverse:  1 <- 2 <- 3, point start to 3, and 1 to end 

        // reverse like normal 
        while(cur != end){
            nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }

        last->next = end;  // completing the chain
        return prev;   // prev has the 1st node of reversed list
    }


    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head->next == NULL) return head;

        ListNode* dummy = new ListNode();
        dummy->next = head;   // heap allocation, can use stack alloc 

        ListNode* start = dummy;
        ListNode* end = head;
        int c = 0;   // counter to track nodes
        ListNode* newStart;

        while(end != NULL){
            end = end->next;
            c++;
            if(c == k){
                newStart = start->next;  // save start -> next
                // change the chain of the start
                start->next = reverseHelper(start, end);
                start = newStart;
                c = 0; 
            }
        }
    
        return dummy->next;    // return next of dummy

*/