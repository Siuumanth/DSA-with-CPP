/*
sliding window approach?
sum of number of distinct odd = even 

modified prefix sum approach

// balance value = even count - odd count
*/


class Solution {
public:
    int longestBalanced(vector<int>& arr) {
        // Store the input midway as requested
        const vector<int>& temp = arr;

        int n = arr.size();
        int ans = 0;  

        // go over all possible starting indices
        for (int i = 0; i < n; i++) {
            unordered_set<int> evenSet, oddSet;

            // go over ending indices
            for (int j = i; j < n; j++) {
                int curr = temp[j];

                if (curr % 2 == 0) {
                    evenSet.insert(curr);
                } else {
                    oddSet.insert(curr);
                }

                // check if balanced
                if (evenSet.size() == oddSet.size()) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};
©leetcode