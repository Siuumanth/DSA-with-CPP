// s = ADAOBEODEBANC
// t = ABC
// ans = BAC

#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<unordered_map>
using namespace std;


class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.length();
        int n = t.length();
        int ans = 0;

        vector<int> need(128, 0);   // to store our need in t
        vector<int> window(128, 0); // to store our current window

        if(n>m) return "";
        else if(n==m && n==1){
            if (s[0] == t[0]) return t;
            else return "";
        }

        // build hash table 
        for(int i = 0; i<n; i++){
            need[ (int) t[i] ]++;
        }

        int c = 0;
        int cur;
        bool valid = false;
        int left = 0, right = 0;
        string sans;
        int minLen = INT_MAX;
        int start = 0; // starting index of the best window


        for(right = 0; right<=m; right++){

            while(valid){       // valid, shrink from left
                if( need[(int)s[left]] > 0 && window[(int)s[left]] == need[(int)s[left]] ){
                    window[(int)s[left]]--;
                    left++;
                    valid = false;
                    c--;
                } 
                else if( need[(int)s[left]] > 0 &&  window[(int)s[left]] > need[(int)s[left]] ){
                    window[(int)s[left]]--;
                    left++;
                }
                else left++;
                start = left;
                ans = right - left + 1;
            }  
            if(right == m) break;

           //invalid, increase window
          // cout << " Need is " << need[(int)s[right]] << " window is " << window[(int)s[right]] << endl;
            if(need[(int)s[right]] > window[(int)s[right]]) c++;
            if(c >= n) valid = true;
            window[(int)s[right]]++;

        }
        start--;
        return s.substr(start, ans + 1);
    }
};

/*
 cur = (int)s[right];

            if(hasht[cur] > 0){    // can increase towards right
                hasht[cur]--;
                c--;
                right++;
                ans = min(ans, right - left + 1);
            }
            else if(hash[cur] == 0 && c != n){     //invalid, shrink till here
                while(c != n){    // shrink left
                    if(hasht[ (int)s[left] ] >= 0){  // in t
                        c++;
                        hasht[ (int)s[left] ]++;
                        left++;
                    }    
                    else  {     // not in t
                        left++;
                    }
                }
                right++;
            }
            else if( hash[cur] == -1){   // invalid window start
                if(c==n){
                    left++;
                    right++;
                }
                else right++;
            } 

            */