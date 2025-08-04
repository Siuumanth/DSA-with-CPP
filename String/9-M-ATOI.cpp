class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.size();
        long long ans = 0;
        bool pos = true;

        // Step 1: Leading White spaces
        while(i < n && s[i] == ' ') i++;
        if( i == n) return 0;

        // Step 2: SignedNess
        if(s[i] == '-'){  // negative
            pos = false; i++;
        }
        else if(s[i] == '+'){
            pos = true, i++;
        }
        else if(s[i] >= '0' && s[i] <= '9') ans = 0;
        else return 0;

        // Step 3: Conversion
        // Remove leading zeroes
        while(i < n && s[i] == '0') i++;

        // count actual numbers
        // Step 4: Parse digits
        while (i < n && s[i] >= '0' && s[i] <= '9') {
            ans = ans * 10 + (s[i] - '0');

            // Early clamp check
            if (pos && ans >= INT_MAX) return INT_MAX;
            if (!pos && -ans <= INT_MIN) return INT_MIN;

            i++;
        }

        return pos ? ans : -ans;

        return ans;

    }
};