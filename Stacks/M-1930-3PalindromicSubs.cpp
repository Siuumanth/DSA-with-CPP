/*
Palindromes shud be of length 3 
Initial approach:
Try all possibilities 

if a three length string has to be a palindrome then only the first and last character have to be equal 
- so maybe a 2d DP ? tat has dp[1st/last char][middle char]
might work but seem there maybe an easier way 

iterate over each element 

mapp[1st/last char][middle char]

"bbcbaba"
mapp[i][j]
Encounter element - ascii is m
- if(mapp[m][m]) == 2 then make it 3 
- if(mapp[])

- if you encounter 2 same characters then all elements in between can form palindromes 
so what if i do 

mapp[1st/last] = set of elements which can come in middle 

and ans is set.size of all 

*/
// cleanest version of my same idea 
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        vector<int> first(26, -1);
        vector<int> last(26, -1);

        // record first and last occurrence
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            if (first[c] == -1) first[c] = i;
            last[c] = i;
        }

        int ans = 0;

        // for each character a..z
        for (int x = 0; x < 26; x++) {
            if (first[x] != -1 && last[x] != -1 && first[x] < last[x]) {
                
                // collect unique chars between first and last
                unordered_set<char> st;
                for (int i = first[x] + 1; i < last[x]; i++) {
                    st.insert(s[i]);
                }
                ans += st.size();
            }
        }

        return ans;
    }
};


// unclean version 
class Solution2{
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        vector<unordered_set<int>> mapp(26); 
        vector<int> locked(26);
        vector<int> freq(26);

        for(char &ch : s){
            // iterate over each char in mapp and add set
            int c = ch - 'a';  // now c is the character
            // c has already occured
            int minus = 0 ; 
            for(int i = 0 ; i < 26; i++){
                // if element has alr occured before then add c to set
                if(freq[i] > 0){
                    mapp[i].insert(c);
                //    cout<< "Inserting " << char(c + 'a') <<" to " << char(i + 'a') << endl;
                    if(i == c && freq[i] == 1) minus = 1; 
                }
            }
            // store ans only when another same character encountered
            locked[c] = mapp[c].size() - minus;
            //cout << "Until now is " << char(c + 'a') << locked[c] << endl;
            freq[c]++;
        }

        // ans is sum of the locked 
        int sum = 0 ;
        for(int num: locked) sum += num;

        return sum;
    }
};

