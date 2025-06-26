
class Solution{
    public:
        int characterReplacement(string s, int k) {
        int n = s.length();
    
        // Frequency array to store count of each character in the current window
        vector<int> freq(26, 0);
        int left = 0, result = 0; // final ans
        int maxCount = 0; // max freq of a single char in window
    
        for (int right = 0; right < n; right++) {
    
            freq[s[right] - 'A']++;  // add cur char in the window
    
            // update the max frequency seen so far in the window
            maxCount = max(maxCount, freq[s[right] - 'A']);
    
            // if the number of characters to change is more than k, shrink 
            int windowSize = right - left + 1;
            if (windowSize - maxCount > k) {
                freq[s[left] - 'A']--;       // decrease freq 
                left++;                      // decrease window 
            }
    
            result = max(result, right - left + 1);
        }
    
        return result;
    }
};

// Shrinking the window one step at a time using an if condition works in this problem because we're always expanding the window gradually, and removing just one character when the window becomes invalid is enough to restore a valid state before the next expansion — so a while loop is not required.





/*
// same way but we calculate freq for all 26 letters
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();

        int left , right, ans, replaceCount;
        int ccount = 0;
        int finalAns = 0;

        for(int i=0; i<26; i++){   // try out all 26 capital letters
            left = 0, ans = 0;
            char main = (char)(65 + ccount);
            replaceCount = 0;

            // main is the current most frequent alphabet( eg: 'A')
            // main count is the number of times main character occurs in the window
            // replaceCount is the number of times transformation occurs( max k times )

            for(right = 0; right < n; right++){
                if(s[right] != main)
                    replaceCount++;
    
                while(replaceCount > k){   // invalid condition
                    if(s[left] != main)    // when max replacement limit reached
                        replaceCount--;
 
                    left++;                // decrease window and count
                }

                ans = max(ans, right - left + 1);
            }
            finalAns = max(finalAns, ans);
            ccount++;
        }

        return finalAns;

    }
};
*/
