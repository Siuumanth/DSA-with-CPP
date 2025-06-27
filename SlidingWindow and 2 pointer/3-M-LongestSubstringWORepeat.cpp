
// use hash table to keep track of last index occured

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> hash(128, -1); // Stores last seen index of each character
        int c = 0, ans = 0, index;
        int n = s.length();
        int current = -1; // Start index of the current window (exclusive)

        if (n == 1) return 1;

        for (int i = 0; i < n; i++) {
            index = (int)s[i]; // Get ASCII value of the character

            if (hash[index] == -1) {
                // Character not seen before
                hash[index] = i;
                c++;
            } else {
                if (hash[index] >= current) {
                    // Character seen inside the current window — shrink window
                    ans = max(ans, c);         // Update max length
                    current = hash[index] + 1; // Move start of window
                    c = i - current + 1;       // Recalculate window size
                    hash[index] = i;           // Update last seen
                } else {
                    // Character seen before but outside current window — continue
                    c++;
                    hash[index] = i;
                }
            }
        }

        return max(ans, c); // Final check to include last window
    }
};

/*
Clean code:
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> hash(128,-1);
        int c = 0, ans = 0, index;
        int n = s.length();
        int current = -1;

        if(n==1) return 1;

        for(int i = 0; i < n; i++) {
            index = (int)s[i];
            if(hash[index] == -1){
                hash[index] = i;
                c++;
            }
            else{
                if(hash[index] >= current){
                    ans = max(ans,c);
                    current = hash[index] + 1;
                    c = i - current + 1;  
                    hash[index] = i;   
                } 
                else{
                    c++;
                    hash[index] = i;
                } 
            }
        }                
        return max(ans,c) ;
    }
};
*/

