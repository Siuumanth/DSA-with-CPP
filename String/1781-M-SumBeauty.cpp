class Solution {
public:
    int beautySum(string s) {
        int n = s.length();
        int minF, maxF;
        int totalBeauty = 0;

        for(int i = 0; i < n ; i++){
            vector<int> freq(26,0);// frequency map for all characters in the subarray 

            for(int j = i; j<n; j++){
                freq[s[j] - 'a']++;
                
                // for each substring recalculate 
                maxF = 0, minF = INT_MAX;

                // Compute max and min frequencies (ignoring 0s)
                for (int k = 0; k < 26; k++) {
                    if (freq[k] > 0) {
                        maxF = max(maxF, freq[k]);
                        minF = min(minF, freq[k]);
                    }
                }

                // Add the beauty of this substring
                totalBeauty += (maxF - minF);
            }
        }

        return totalBeauty;

    }
};
