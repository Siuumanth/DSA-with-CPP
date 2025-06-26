




#include<vector>
using namespace std;

class Solution {
    public:
        int singleNonDuplicate(vector<int>& nums) {
            int start = 0;
            int n = nums.size();
            int end = n - 1;
            int mid;
    
            // Edge case: If there's only one element in the array, return it 
            if (end == 0) return nums[0];
    
            // Binary search approach
            while (end >= start) {
    
                mid = (start + end) / 2;  // Calculate middle index
    
                // If the first element is unique (edge case)
                if (mid == 0 && nums[mid] != nums[mid + 1])
                    return nums[0];
    
                // If the last element is unique (edge case)
                else if (mid == n - 1 && nums[mid - 1] != nums[mid])
                    return nums[mid];
    
                // If mid itself unique element (both neighbors are different)
                if (nums[mid - 1] != nums[mid] && nums[mid + 1] != nums[mid])
                    return nums[mid];
    
                // Check if mid is at an **even index**
                if (mid % 2 == 0) {  
                    // If the previous element same, unique element is on the left
                    if (nums[mid - 1] == nums[mid])
                        end = mid - 1;  
                    else 
                        start = mid + 1;  // Unique element is on the right
                } 
                else {  // mid is at an **odd index**
                    // If previous element same, unique element is on the right
                    if (nums[mid - 1] == nums[mid])
                        start = mid + 1;  
                    else 
                        end = mid - 1;  // Unique element is on the left
                }
            }
            
            // If loop breaks, return the element at mid (final candidate)
            return nums[mid];
        }
    };
    