#include<iostream>
using namespace std;

#include<stack>


void insertSorted(stack<int>& st, int val){
    // val is the insertion element that we need to insert at the right place
    if(st.empty() || val >= st.top()){
        st.push(val);
        return;
    }

    int top = st.top();   // saving top temperorily for pusing later
    st.pop();
    insertSorted(st, val);
    st.push(top);
}


void sortStack(stack<int> & st){
    // base case
    if(st.empty()) return;

    // actual insertion
    int top = st.top();
    st.pop();   // save top element and pop top
    
    // recursively call the next elemnts to be sorted
    sortStack(st);
    insertSorted(st, top);

}



int main(){

    // build a stack
    stack<int> st;
    st.push(3);
    st.push(1);
    st.push(4);
    st.push(2);

    sortStack(st);

    while(!st.empty()){
        cout<<st.top();
        st.pop();
    }


    return 0;
}