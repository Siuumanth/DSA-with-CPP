
// Dutch National Flag algorithm: arrange 0s, 1s, and 2s by maintaining three pointers (low, mid, high) and swapping elements into correct regions.


// Helper function to swap two elements in the array
void swap(vector<int>& nums, int a, int b){
    int temp = nums[b];
    nums[b] = nums[a];
    nums[a] = temp;
}

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int low = 0, mid = 0, high = n - 1;

        // Process elements until mid pointer crosses high pointer
        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums, low, mid);
                low++;
                mid++;
            }
            else if (nums[mid] == 1) {
                // If current element is 1, it's already in correct place
                mid++;
            }
            else if (nums[mid] == 2) {
                swap(nums, high, mid);
                high--;
                // Do not increment mid cuz swapped element might be unsorted
            }
        }
    }
};


