// Using a stack 
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        vector<int> st;  // vector as a stack  
        int n = s.length();

        for(int i = 0; i < n; i++){
            if(s[i] == '(') st.push_back(i);   // stack will have the indexes
            else if(s[i] == ')'){
                if(st.empty()) st.push_back(i);
                else if(s[st.back()] == '('){   // pair and pop
                    st.pop_back();
                }
                else st.push_back(i);   // if stack is empty or has ')' push it 
            }
            // stack only runs for ()
        }

        if(st.empty()) return s;   // string is already valid 

        // Now our stack will only have the invalid indexes, we will now remove them
        string ans = ""; 
        int c = 0;   // counter for vector stack
        int n1 = st.size();
        for(int i = 0; i < n ; i++){
            if(c < n1 && i==st[c]) c++;  // skip invalid element 
            else ans += s[i];
        }

        return ans;
    }
};