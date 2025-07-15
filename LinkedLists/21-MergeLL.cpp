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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        // Similar to simple merge in arrays
        
        ListNode* first = list1;
        ListNode* second = list2;

        ListNode* head = new ListNode();
        ListNode* temp = head;

        while(first != NULL && second != NULL){
            if(first->val <= second->val){
                temp->next = first;
                first = first -> next;
            } 
            else{
                temp->next = second;
                second = second->next;
            }
            temp = temp->next;
        }

        if(first != NULL){
            temp->next = first;
        }
        else if(second != NULL){
            temp->next = second;
        }

        return head->next;
    }
};