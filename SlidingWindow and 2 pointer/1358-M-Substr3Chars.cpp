
class Solution {
public:
    int numberOfSubstrings(string s) {
        int count = 0;
        int left = 0;
        unordered_map<char, int> char_count = {{'a', 0}, {'b', 0}, {'c', 0}};
        
        for (int right = 0; right < s.length(); ++right) {
            char_count[s[right]]++;
            
            while (char_count['a'] > 0 && char_count['b'] > 0 && char_count['c'] > 0) {
                count += s.length() - right;
                char_count[s[left]]--;
                left++;
            }
        }
        
        return count;
    }
};

/*
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        
        int cnt = 0, ans = 0; 
        int left = 0, right = 0;
        
        unordered_map<char, int> abc = {{'a', 0}, {'b', 0}, {'c', 0}};
        unordered_map<char, bool> map = {{'a', 0}, {'b', 0}, {'c', 0}};

        // finding ending of smallest mid substring
        while(cnt < 3 && right < n){
            if(map[ s[right] ] == false){
                map[ s[right] ] = true;
                cnt++;
            } 
            abc[s[right]]++;    // maintaining count of each character
            right++;
        }
        right--;
        // now right has the ending 

        int i = 0;
        while(1){
            if(abc[ s[i] ] - 1 == 0){
                left = i;
                break;
            }
            abc[ s[i] ]--;
            i++;
        }

        // now we have right and left of the first min substring containing a,b,c

        // all permutations towards the left
        ans += left; 

        // finding all permutations towards the right
        // using sliding window

        // abc has the count of all chars inside window

        for(){
            ans += right - left + 1;   // total num of possible comb from current wd

            if(abc[s[left]] - 1 == 0){
                left++;
                abc[ s[left] ]--;
                while(abc[ s[left] ] != 0){
                    right++;
                    abc[s[right]]++;
                }

            }
    
        }




        return ans;

    }
};

*/

/*
        // find starting point 
        for(i = 0; i < n && cnt != 3 ; i++){
            if( map[s[i]] != map.end()){
                if ( abc[ map[s[i]] ] == false ){
                    abc[ map[s[i]] ] = true;
                    left = min(left, i);
                    cnt++;
                }
            }
        }
*/