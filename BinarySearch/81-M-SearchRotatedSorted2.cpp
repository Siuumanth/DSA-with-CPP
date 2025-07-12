// 5     v
// 1 0 1 1 1 1 1
// 1 1 1 1 1 0 1

// See in the above cases, we can conclude that a O(logn) time complexity is not
// possible, so lets think beyond it

/*
    🔍 Intuition:
    This is a variation of binary search applied to a rotated sorted array
    which may contain duplicates. Normally, in a rotated sorted array,
    one half is guaranteed to be sorted. But when duplicates exist,
    we can't always determine which half is sorted, especially when
    arr[low] == arr[mid] == arr[high].

    🧠 Approach:
    - Perform standard binary search with conditions adjusted for rotation.
    - If we can determine the sorted half (left or right), check if the target
   lies within it.
    - If duplicates make it ambiguous (i.e., arr[low] == arr[mid] or arr[mid] ==
   arr[high]), then shrink the search space linearly by moving low or high
   inward by 1.
    - This degrades to O(n) in worst-case scenarios (e.g., all elements are the
   same), but performs close to O(log n) in average cases.

    ⚠️ Edge Cases:
    - The array contains only one or two elements.
    - All elements are the same.
    - Target is at the pivot (rotation point).
    - Target is not present at all.
    - Duplicates surround the mid-point, making it ambiguous which side is
   sorted.
*/

class Solution {
public:
    bool search(vector<int>& arr, int target) {
        int n = arr.size();
        int low = 0, high = n - 1;
        int mid;

        while (low <= high) {
            mid = low + (high - low) / 2;

            // Base case: direct match
            if (arr[mid] == target)
                return true;

            // Left half is sorted
            if (arr[low] < arr[mid]) {
                // Check if target lies in this sorted left half
                if (target >= arr[low] && target < arr[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            }

            // Right half is sorted
            else if (arr[mid] < arr[high]) {
                // Check if target lies in this sorted right half
                if (target > arr[mid] && target <= arr[high])
                    low = mid + 1;
                else
                    high = mid - 1;
            }

            // Ambiguous case: duplicates make it unclear
            // This is responsible for O(n)
            else if (arr[low] == arr[mid]) {
                // Skip one duplicate from the left
                low++;
            }

            else if (arr[mid] == arr[high]) {
                // Skip one duplicate from the right
                high--;
            }
        }

        // Target not found
        return false;
    }
};

/*
1. left sorted
*/