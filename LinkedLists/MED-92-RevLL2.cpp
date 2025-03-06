 //Definition for singly-linked list.
 struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    public:
        ListNode* reverseBetween(ListNode* head, int left, int right) {
            if (left == right) return head;  // No change needed if left == right
    
            int c = 1;
            ListNode* cur = head;
            ListNode* prevleft = nullptr;  // Node before 'left' position
    
            // Move to the 'left' position
            while (c != left) {
                prevleft = cur;
                cur = cur->next;
                c++;
            }
    
            ListNode* leftNode = cur;  // First node of the sublist to reverse
            ListNode* prev = nullptr;
            ListNode* nxt = nullptr;
    
            // Reverse nodes from 'left' to 'right'
            while (c != right) {
                nxt = cur->next;
                cur->next = prev;
                prev = cur;
                cur = nxt;
                c++;
            }
    
            ListNode* righthalf = cur->next;  // Store node after 'right'
            cur->next = prev;  // Final reversal step
    
            // If 'left' is 1, update head
            if (prevleft == nullptr) {
                head->next = righthalf;
                return cur;
            }
    
            prevleft->next = cur;  // Connect first part to reversed section
            leftNode->next = righthalf;  // Connect reversed section to remaining list
    
            return head;
        }
    };
    