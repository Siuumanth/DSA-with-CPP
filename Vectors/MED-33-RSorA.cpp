#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<unordered_map>
using namespace std;


class Solution {
    public:
        int search(vector<int>& nums, int target) {
            int st = 0, end = nums.size() - 1, mid;
            while(st<=end){
                mid = st + (end - st)/2;
                if(nums[mid] == target) return mid;
    
                if(nums[st] <= nums[mid]){ // left sorted
                    if(nums[st] <= target && target <= nums[mid])
                      end = mid - 1;
                    else st = mid + 1;
                }
                else{      //right sorted
                    if(nums[mid] <= target && target <= nums[end])
                      st = mid + 1;
                    else end = mid - 1;
                }
            }
            return -1;  
        }
    };
    
    
    /*Key Observations
    Even though the array is rotated, at least one half of the array is always sorted.
    We can decide which half to discard based on whether the target lies inside that sorted half.
    Step-by-Step Explanation of Modified Binary Search
    Find the middle element nums[mid].
    Check if nums[mid] is the target → If yes, return mid.
    Determine which half is sorted:
    If nums[st] ≤ nums[mid], then left half is sorted.
    Else, right half is sorted.
    Decide which half to search in:
    If the left half is sorted (nums[st] ≤ nums[mid]):
    If target lies within [nums[st], nums[mid]], search in left half (end = mid - 1).
    Else, search in right half (st = mid + 1).
    If the right half is sorted:
    If target lies within [nums[mid], nums[end]], search in right half (st = mid + 1).
    Else, search in left half (end = mid - 1).
    Repeat steps 1-4 until st > end.*/
    