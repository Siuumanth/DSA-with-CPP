#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;


class Solution {
public:
    int searchInsert(const vector<int>& nums, int target) {
            int low=0,high = nums.size() - 1;     
            while(high>=low){
                int mid = (low + high)/2;
                if(nums[mid] == target)
                   return mid;
                else if(target>nums[mid])
                   low = mid + 1;
                else
                   high = mid - 1;
            }
            return low ;
    }
};