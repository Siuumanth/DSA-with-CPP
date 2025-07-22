class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0, maxLen = 1;
        int n = s.length();

        for (int i = 0; i < n; ++i) {
            // Odd-length palindromes (centered at i)
            int low = i, high = i;
            while (low >= 0 && high < n && s[low] == s[high]) {
                if (high - low + 1 > maxLen) {
                    start = low;
                    maxLen = high - low + 1;
                }
                --low;
                ++high;
            }

            // Even-length palindromes (centered between i and i+1)
            low = i, high = i + 1;
            while (low >= 0 && high < n && s[low] == s[high]) {
                if (high - low + 1 > maxLen) {
                    start = low;
                    maxLen = high - low + 1;
                }
                --low;
                ++high;
            }
        }

        return s.substr(start, maxLen);
    }
};

// eg: "abebaeabc" => "baeab"


/*
int len = 0, maxLen = 1;
        int low,high;

        int n = s.length();
        for(int i = 0; i < n; i++){
            int j = n-1;
            while(i < j){
                int k = i;
                // choosing a starting point for palindrome verification 
                while(j > k && s[k] != s[j]) j--;
                if( j <= k) break;  // exit if converge

                len = 0;
                while(s[k] == s[j] && k < j){   // palindrome verification
                    len++;
                    k++;
                    j--;
                }

                if(k < j) continue;

                // len correction
                if(k == j) len = 2  * len + 1;
                else if(j < k) len = 2 * len;

                if(j <= k){
                    if( len > maxLen){
                        maxLen = len;
                        start = i;
                    }
                }
            }
        }
        cout << start << maxLen;
        */