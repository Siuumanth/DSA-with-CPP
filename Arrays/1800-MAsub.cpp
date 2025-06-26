#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<unordered_map>
using namespace std;



class Solution {
    public:
        int maxAscendingSum(vector<int>& nums) {
            int sum = nums[0];
            int maxSum = 0;
            int i = 0;
            maxSum = max(sum,maxSum);
            while(i < nums.size() - 1){
                if(nums[i+1] > nums[i])
                    sum += nums[i+1];
                else sum = nums[i+1];
                maxSum = max(sum,maxSum);
                i++;
            }
            return maxSum;
        }
    };