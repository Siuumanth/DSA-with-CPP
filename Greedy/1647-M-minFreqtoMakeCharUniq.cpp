/*
No need DP 
using a freq map - most prolly

1. make a freq map 
2. Identify the elements with same frequencies
3. find an algoritm that eliminates it

- freq cant be increased it can only be decreased 
- We can aim at the highest possible freq, and try to make sure the surrounding elements dot get the same freq, by maybe assigning 
*/

class Solution {
public:
    int minDeletions(string s) {
        int n = s.size();
        vector<int> freq(26, 0);   // freq map
        int maxFreq = 0;
        int ans = 0;

        // Step 1: Find freq map
        for(int i = 0; i < n; i++){
            freq[s[i] - 'a']++;
            maxFreq = max(maxFreq, freq[s[i] - 'a']);
        }

        // Upper limit for our freq is maxFreq;

        // Step 2: sort freq map
        sort(freq.begin(), freq.end());

        // Step 3: unordered set / bool array to store the possible frequencies 
        vector<bool> set(maxFreq + 1, true);

        // now set will be a boolean array which has true for usable freq and false for unusable freq
        for(int i = 0; i < 26; i++){  // iterate over freq map and try to fix the string
            if(freq[i] != 0 && set[freq[i]] == false){
                // we encounter an invalid freq
                // we have to decrease it to the next possible biggest freq
                int j = freq[i];
                while(j > 0 && set[j] == false){
                    j--;  // find a better spot for i
                }
                // if j = 0, then remove all chars 
                set[j] = false;  // occupy that freq
                ans += freq[i] - j;   // add how many characters were removed 
            }

            if(freq[i] > 0) set[freq[i]] = false;;

        }
        return ans;
    }
};