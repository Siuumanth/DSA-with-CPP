// Smallest possible number shud be retrived
// this means this problem is similar to lexicographically 

// Greedy approach:
// Use a monotonic stack and add only smaller elements and subtract k each time
// Handle the 3 following edge cases

class Solution {
public:
    string removeKdigits(string s, int k) {
        int n = s.length();
        // edge case 1, remove all digits
        if(k == n) return "0";

        string st;  // custom monotonic increasing stack

        for(int i = 0; i < n ; i++){
            while(!st.empty() && k > 0 && s[i] < st.back()){
                st.pop_back();
                k--;
            }
            st.push_back(s[i]);
        }

        // edge case 2, s was in ascending order so k > 0
        while(k > 0){
            st.pop_back();
            k--;
        }

        // edge case 3, if string has leading zeroes 
        int i = 0;
        while(i < st.size() && st[i] == '0') i++;

        if(i == 0) return st; // no leading zeroes

        string res = st.substr(i);
        return res.empty() ? "0" : res;
    }
};