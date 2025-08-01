/*
We will use a monotonically custom decreasing stack and use a greedy approach 
- We will keep popping the stack untill the top is lexicographically smaller the current
- Before popping we check a condition: if the current index is smaller than last seen of that element, to make sure we dont pop the elements that will not appear again 
*/
class Solution {
public:
    string removeDuplicateLetters(string s) {
 
        // map to store last seen of the strings
        unordered_map<char, int> mapp;
        int n = s.length();

        // Step 1: store last seen map for each alphabet
        for(int i = 0; i < n; i++) mapp[s[i]] = i; 

        string st;  // custom monotonic stack 
        vector<int> seen(26, 0); // to keep track of elements(or set works too)

        for(int i = 0; i < n ; i++){
            if(seen[s[i] - 'a'] != 0) continue;
            // keep popping
            while(!st.empty() && s[i] <= st.back() && mapp[st.back()] > i){
                seen[st.back() - 'a'] = 0;
                st.pop_back();
            }   

            seen[s[i] - 'a'] = 1;
            st.push_back(s[i]);
        }
 
        return st;
    }
};