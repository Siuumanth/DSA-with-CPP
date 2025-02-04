
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 



// best solution 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0,digit;
        digit = l1->val + l2->val;
        carry = digit/10;
        ListNode* head = new ListNode(digit % 10);
        ListNode* temp = head;
        l1 = l1->next, l2 = l2->next; 
        while(l1 || l2 || carry){
            digit = carry;
            if(l1){
                digit += l1->val;
                l1 = l1->next;
            }
            if(l2){
                digit += l2->val;
                l2 = l2->next;
            }
            carry = digit/10;
            temp->next = new ListNode(digit % 10);
            temp = temp->next;
        }
        return head;
    }
};


//optimal approach, traverses and creates new nodes without intermediates, but the code is not optimised and it unnecessarily long

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        int digit;
        digit = l1->val + l2->val;
        if(digit > 9){
            digit -= 10;
            carry = 1;  
        } else carry = 0;
        ListNode* head = new ListNode(digit);
        ListNode* temp = head;
        l1 = l1->next;
        l2 = l2->next;
        
        while(l1 != nullptr && l2 != nullptr){
            digit = l1->val + l2->val + carry;
            if(digit > 9){
                digit -= 10;
                carry = 1;
            } else carry = 0;
            ListNode* newNode = new ListNode(digit);
            temp->next = newNode;
            temp = temp->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        if(l1==nullptr && l2!=nullptr){
            while(l2!=nullptr){
                digit = l2->val + carry;
                if(digit>9){
                    digit -=10;
                    carry = 1;
                }
                else carry = 0;
                ListNode* newNode = new ListNode(digit);
                temp->next = newNode;
                temp = temp->next;
                l2 = l2->next;

            }
        }
        else if(l2==nullptr && l1!=nullptr){
            while(l1!=nullptr){
                digit = l1->val + carry;
                if(digit>9){
                    digit -=10;
                    carry = 1;
                }
                else carry = 0;
                ListNode* newNode = new ListNode(digit);
                temp->next = newNode;
                temp = temp->next;
                l1 = l1->next;

            }
        }
        else if(l1==nullptr && l2 == nullptr && carry==1){
            digit = carry;
            ListNode* newNode = new ListNode(digit);
            temp->next = newNode;
        }
        if(carry==1){
            digit = carry;
            ListNode* newNode = new ListNode(digit);
            temp->next = newNode;
        }
        return head;
    }
};


// basic approach, integer overflow as linked list length can be 1 < len < 100
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int ten = 1;
        int n1 = 0,n2 = 0;
        while(l1 != nullptr){
           n1 += l1->val * ten;
           l1 = l1->next;
           ten *= 10;
        }
        ten = 1;
        while(l2 != nullptr){
           n2 += l2->val * ten ;
           l2 = l2->next;
           ten *= 10;
        }
        int n = n1 + n2;
        ListNode* head = new ListNode(n%10);
        ListNode* temp = head;
        n /= 10;
        while (n > 0) {
            int digit = n % 10;  
            ListNode* newNode = new ListNode(digit);  
            temp->next = newNode; 
            temp = temp->next;
            n /= 10;  
        }
        return head;
    }
};