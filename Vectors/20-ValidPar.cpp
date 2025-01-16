#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

#include<stack>
char getBracket(char cur){
    switch(cur){
        case '(': return ')';
        case '[' : return ']';
        case '{' : return '}';
        default : return 'x';
    }
}

class Solution {
public:
    bool isValid(string str){
        stack<char> st;

        for(int i = 0; i < str.size() ; i++){
            if(str[i] == '(' || str[i] == '[' || str[i] == '{'){
                st.push(str[i]);
            }
            else{
                if(!st.empty() && getBracket(st.top()) == str[i])
                  st.pop();               
                else
                    return false;               
            }
    }

   return st.empty();  
    }
};


