// Vertical scanning 
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        // Iterate character by character through the first string
        for (int i = 0; i < strs[0].length(); i++) {
            char ch = strs[0][i];  // Get the i-th character from the first string

            // Compare this character with the i-th character of all other strings
            for (int j = 1; j < strs.size(); j++) {
                // If the current string is shorter than i, or there's a mismatch
                if (i >= strs[j].length() || strs[j][i] != ch) {
                    return strs[0].substr(0, i);
                }
            }
        }

        // If no mismatch found, the entire first string is the common prefix
        return strs[0];
    }
};
