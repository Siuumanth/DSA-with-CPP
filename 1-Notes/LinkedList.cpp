#include<iostream>
using namespace std;

// LL funtions: push_front, push_back, pop_front, pop_back

class Node{
    public:
        int data;
        Node* next;

        Node(int val){
            data = val;
            next = NULL;
        }

        
};

class List{
    Node* head;
    Node* tail;
    int size;

    public:
      List(){
        head = tail = NULL;
      }


      void push_front(int val){
           Node* node = new Node(val);  // dynamic object, persists after func return
           // new returns a pointer to the new object 
           // If we do with Node node(val), it not suitable, its static implementation 
           // as node exists only within the function

           if(head == NULL){
               head = tail = node;
               return;
           }
           node->next = head;
           head = node;
      }

        void push_back(int data){
            Node* node = new Node(data);
    
            if(tail == NULL){
                head = tail = node;
                return;
            }
    
            tail->next = node;
            tail = node;
        }

        void pop_front(){
            if(head == NULL){
                return;
            }

            Node* temp = head;
            head = head->next;
            delete temp;

            if(head == NULL){
                tail = NULL;
            }
        }

        void pop_back() {
            if (tail == NULL) {
                return;
            }
        
            if (head == tail) {
                delete head;
                head = tail = NULL;
                return;
            }
        
            Node* temp = head;
            while (temp->next != tail) {
                temp = temp->next;
            }
        
            delete tail;
            tail = temp;
            tail->next = NULL;
        }

        void insertAtPosition(int pos, int data){
            Node* temp = head;
            Node* nodeToInsert = new Node(data);
            int cnt = 0;
            while(cnt < pos-1){
                temp = temp->next;
                cnt++;
            }
            nodeToInsert->next = temp->next;
            temp->next = nodeToInsert;
        }

        bool search(int key){
            Node* temp = head;
            while(temp != NULL){
                if(temp->data == key){
                    return true;
                }
                temp = temp->next;
            }
            return false;
        }


      
      void printLL(){
          Node* temp = head;
          while(temp != NULL){
              cout<<temp->data<<" ";
              temp = temp->next;
          }
          cout<<endl;
      }

};       





int main(){

    List ll;
    ll.push_front(5);
    ll.push_front(10);
    ll.push_front(15);
    ll.printLL();
    

    return 1;
}