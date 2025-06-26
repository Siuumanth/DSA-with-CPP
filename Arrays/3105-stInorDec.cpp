
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<unordered_map>
using namespace std;



class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
       int si = 0,sd = 0,maxsi = 0, maxsd = 0;
       for(int i = 0 ; i < nums.size() - 1 ; i++){
           if(nums[i+1] > nums[i]){
            si++;
            maxsi = max(maxsi,si);
            sd = 0;
           }
           else if(nums[i+1] < nums[i]){
            sd++;
            maxsd = max(maxsd,sd);
            si = 0;
           }
           else {
            sd = 0;
            si = 0;
           }
       }  
       return max(maxsi,maxsd) + 1;
    }
};