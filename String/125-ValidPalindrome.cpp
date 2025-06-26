
bool isAlphanumeric(char ch){
    if(ch >= '0' && ch<='9') return true;
    ch = tolower(ch);
    if(ch>='a' && ch<='z') return true;
    return false;
}


class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        int st = 0, end = n-1;
        while(st < end){
            if(!isAlphanumeric(s[st])){
                st++;
                continue;
            } 
            else if(!isAlphanumeric(s[end])){
                end--;
                continue;
            }

            if(tolower(s[st]) != tolower(s[end])) return false;

            st++;
            end--;
        }
        return true;
    }
};
