
// Intuition:
    // 1. Find the first "pivot" where nums[i] < nums[i+1].
    // 2. Swap the pivot with the smallest element greater than it on the right.
    // 3. Reverse the suffix after the pivot to get the smallest lexicographical order.

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size() - 1;
        int pivot = -1;

        // 1. Find the pivot: the first number smaller than its next number
        for(int i = n - 1; i >= 0; i--) {
            if(nums[i] < nums[i + 1]) {
                pivot = i;
                break;
            }
        }

        // If no pivot is found, reverse the entire array
        // (it's already the largest permutation)
        if(pivot == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        int next;
        // 2. Find the smallest element greater than pivot from the right side
        for(int i = n; i >= 0; i--) {
            if(nums[i] > nums[pivot]) {
                next = i;
                break;
            }
        }

        // 3. Swap the pivot with the next larger element
        int temp = nums[pivot];
        nums[pivot] = nums[next];
        nums[next] = temp;

        // 4. Reverse the subarray after the pivot to get the next permutation
        reverse(nums.begin() + pivot + 1, nums.end());
    }
};
