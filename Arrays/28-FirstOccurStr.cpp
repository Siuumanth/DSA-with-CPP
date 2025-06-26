#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.length()<needle.length()) 
          return -1;
        int hlen = haystack.length();
        int nlen = needle.length();
        for(int i = 0;i<= hlen - nlen ;i++){
            if(haystack.substr(i,nlen) == needle )
              return i;
        }
        return -1;
    }
};