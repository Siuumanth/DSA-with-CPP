/*
// Definition for a Node->
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

// Approach 2: interleaving
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return nullptr;
        Node* cur = head;
        Node* temp;

    // 1st pass: Interleaving, creating alternative sequence of new and old
    // also passing data 
        while(cur != NULL){
            temp = new Node(cur->val);
            temp->next = cur->next;
            cur->next = temp;
            cur = cur->next->next;
        }

        // O -> N -> O -> N -> O -> N -> null 

        // 2nd pass: Copying randoms 
        cur = head;
        Node* newHead = cur->next;
        Node* newCur = newHead;

        while(cur != NULL){
            // copy random
            if(cur->random != NULL){
                newCur->random  = cur->random->next;
            }
            else newCur->random = NULL;

            cur = cur->next->next;
            if(cur != NULL) newCur = cur->next;
        }

        // 3. Restoring original list and seperating lists
        cur = head;
        newHead = cur->next;
        newCur = newHead;

        while(cur != NULL){
            cur->next = cur->next->next;
            cur = cur->next;
            if(cur == NULL) break;
            newCur->next = cur->next;
            newCur = newCur->next;
        }

        return newHead;
    }
};



/*
// map to store old : new addresses 
        unordered_map<Node*, Node*> mapp;
        Node* cur = head;

        Node* newHead = new Node(cur->val);
        Node* newCur = newHead;

        // very important initialisation, or it will break my code as 
        // null can be mapped to some other pointer
        mapp[NULL] = NULL;

        // Creating hash map for addresses, and copying data 
        while(cur != NULL){
            // Creating a temp node, or using existing one 
            Node* temp;
            if( mapp.find(cur) != mapp.end()){
                temp = mapp[cur];
            }
            else{
                temp = new Node(cur->val);  // creating new in the heap
                mapp[cur] = temp;
            }

            // copying next  
            if(mapp.find(cur->next) != mapp.end()){
                temp->next = mapp[cur->next];
            }
            else{ 
                Node* newNext = new Node(cur->next->val);
                mapp[cur->next] = newNext;
                temp->next = newNext;
            }
            
            // copying random
            if(mapp.find(cur->random)!= mapp.end()){
                temp->random = mapp[cur->random];
            }
            else{ 
                Node* newRandom = new Node(cur->random->val);
                mapp[cur->random] = newRandom;
                temp -> random = newRandom; 
            }

            newCur->next = temp;
            newCur = newCur->next;

            cur = cur->next;
        }

        return newHead->next;
*/