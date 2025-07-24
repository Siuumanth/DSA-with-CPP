class Solution {
public:
    bool isAnagram(string s, string t) {
        // Using a hash map
        vector<int> freq(26,0);

        // store freq of s
        for(char ch : s){
            freq[ ch - 'a']++;
        }
        
        // decrement freq in relation to t
        for(char ch : t){
            freq[ ch - 'a']--;
        }

        // iterate over freq and check if there are no > 0 elements
        for(int i : freq){
            if(i!=0) return false;
        }

        return true;

    }
};