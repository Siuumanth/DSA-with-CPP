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



// 2. Slow Fast approach
// Solving in single approach, very imp 
// slow pointer : moves 1
// fast pointer : moves 2
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        // slow = slow -> next
        // fast = fast -> next -> next

        while( fast != nullptr && fast->next != nullptr){
            slow = slow -> next;
            fast = fast->next->next;

        }

        return slow;
    }
};

/*
// 1. Brute Force approach
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* temp = head;

        int c = 0;

        while(temp != nullptr){
            c++;
            temp = temp->next;
        }

        c = c/2 + 1;    // finding proper value of middle element

        int it = 1;
        temp = head;

        while(it < c){
            temp = temp -> next;
            it++;    
        }

        return temp;
        
    }
};

*/