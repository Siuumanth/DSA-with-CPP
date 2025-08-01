/*
Approach: Monotonic Stack + Contribution Technique

Problem:
- We need to find the sum of ranges (max - min) for all subarrays of the given array.

Key Insight:
- For each element, calculate how many subarrays consider it as the maximum and how many as the minimum.
- Then compute each element's contribution to the total sum of subarray ranges.

Steps:
1. Use monotonic stacks to find:
   - For each index, the Previous Less/Greater Element (PLE/PGE) and Next Less/Greater Element (NLE/NGE).
   - These define the bounds in which an element is the minimum/maximum.

2. For every element at index `i`:
   - Its contribution when it's the **maximum** = `nums[i] * (i - PGE) * (NGE - i)`
   - Its contribution when it's the **minimum** = `nums[i] * (i - PLE) * (NLE - i)`

3. Subtract the total contribution when it's a minimum from when it's a maximum
   to get the total range sum of all subarrays.

Time Complexity: O(n)
- Each index is pushed and popped at most once in each monotonic stack.

Space Complexity: O(n)
- For stacks and storing PLE/NLE arrays.
*/


class Solution {
public:
    long long getContribution(vector<int>& nums, bool isMax) {
        int n = nums.size();
        vector<int> ple(n), nle(n);  // previous and next lesser/greater
        stack<int> st;

        // Next less/greater
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && (isMax ? nums[i] >= nums[st.top()] : nums[i] <= nums[st.top()])) {
                st.pop();
            }
            nle[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Prev less/greater
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && (isMax ? nums[st.top()] < nums[i] : nums[st.top()] > nums[i])) {
                st.pop();
            }
            ple[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        // Contribution sum
        long long total = 0;
        for (int i = 0; i < n; ++i) {
            long long left = i - ple[i];
            long long right = nle[i] - i;
            total += (long long)nums[i] * left * right;
        }

        return total;
    }

    long long subArrayRanges(vector<int>& nums) {
        return getContribution(nums, true) - getContribution(nums, false);
    }
};
