class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length() - 1;
        int i = n;

        while(i >= 0 && s[i] == ' '){
            i--;
        }
        
        int ans = 0;
        while(i>=0 && s[i] != ' '){
            ans++;
            i--;
        }

        return ans;
        
    }
};