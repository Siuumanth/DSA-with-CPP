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
