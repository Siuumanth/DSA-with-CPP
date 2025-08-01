class Solution {
public:
    int calcMaxGain(string& s, int x, int y, char a, char b){
        // assume x is greater
        vector<char> st;
        int n = s.length();
        int score = 0;

        for(int i = 0; i< n; i++){
            if(!st.empty() && st.back() == a && s[i] == b){
                score += x;
                st.pop_back();
            }
            else st.push_back(s[i]);
        }
        // 5 5 
        // st has currently cdbcab

        // new stack for getting y points
        stack<char> st2;
        for(int i = 0; i< st.size(); i++){
            if(!st2.empty() && st2.top() == b && st[i] == a ){
                score += y;
                st2.pop();
            }
            else st2.push(st[i]);
        }

        return score;

    }

    int maximumGain(string s, int x, int y) {
        stack<char> st;
        int n = s.length();
        int score = 0;

        // interchange x and y based on which is greater 
        if(x >= y) score = calcMaxGain(s, x, y, 'a', 'b');
        else score = calcMaxGain(s, y, x, 'b', 'a');
        
        return score; 
    }
};

/*
initial non working code, doesnt follow greedy

class Solution {
public:
    int maximumGain(string s, int x, int y) {
        stack<char> st;
        string ab = "ab";
        string ba = "ba";
        int n = s.length();
        int score = 0;

        for(int i = 0; i < n; i++){
            if(!st.empty()){
                if(st.top() == 'a' && s[i] == 'b'){
                    st.pop();
                    score += x;     // ab found
                }
                else if(st.top() == 'b' && s[i] == 'a'){
                    st.pop();
                    score += y;    // ba found
                }
                else{
                    st.push(s[i]);
                }
            }
            else{   // stack is empty so just push elemnt 
                st.push(s[i]);
            }
        }
        
        return score; 
    }
};

*/