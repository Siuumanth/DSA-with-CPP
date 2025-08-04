class Node{
    public:
       Node* prev;
       Node* next;
       int key;
       int val;

       Node(int k, int v){
        key = k;
        val = v;
        prev = NULL;
        next = NULL;
       }
};

class LRUCache {
public:
    int n;
    int c;
    unordered_map<int, Node*> mapp;   // key : LL
    Node* head, *tail; 

    LRUCache(int capacity) {
        n = capacity;
        c = 0;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        // for getting node, we use the node and return key
        if(mapp.find(key) != mapp.end()){  // key present

            // using node, move node to last
            Node* cur = mapp[key];

            useNode(cur);
            return cur->val;
        }
        return -1;  // not exist
    }
    
    void put(int key, int val) {
       // Putting conditions:
       // if Node exist: use it
       // if not exist: capacity full, pop first and add it, else just add it

       if(mapp.find(key) != mapp.end()){  // Node already exists 
           Node* cur = mapp[key];
           useNode(cur);
           cur->val = val;
       }
       else{    // node not exist

            // Step 1: add new node to the last
            Node* cur = new Node(key, val);
            mapp[key] = cur;

            tail->prev->next = cur;   // adding cur to last
            cur->prev = tail->prev;

            cur->next = tail;   // linking tail and cur
            tail->prev = cur;

            if(c == n){   // capacity full
               // Step 2: delink and delete first node (LRU)
               Node* lru = head->next;

               head->next = lru->next;  // de linking lru
               lru->next->prev = head;

               mapp.erase(lru->key);  // Must remove the key from map
               
               delete lru;  // destory LRU node
           }
           else{  // capacity is not FULL
               c++;
           }
       }

    }
    void useNode(Node* cur){
        // de link node
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;

        tail->prev->next = cur;  // linking last node to current
        cur->prev = tail->prev;

        cur->next = tail;   // linking cur to tail
        tail->prev = cur;
    }
};



/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
 