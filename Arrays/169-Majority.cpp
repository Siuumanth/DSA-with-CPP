// optimised approach: time complexity is O(nlogn)
/*class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());

        int ans = nums[0],freq = 1;
        for(int i = 1;i<n;i++){
            if(nums[i] == nums[i-1]){
                freq++;
            } else{
              freq = 1;
              ans = nums[i];
            }
            if(freq>n/2) return ans;
        }
        return ans;
    }
};*/ 


//OPTIMISED APPROACH:
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int freq = 0,ans = 0,n = nums.size();
        for(int i =0; i<n;i++){
            if(freq == 0)
                ans = nums[i];
            if(ans == nums[i])
                freq++;
            else  
                freq--;
        }
        return ans;
    }
};