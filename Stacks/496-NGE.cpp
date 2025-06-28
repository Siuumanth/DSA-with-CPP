
class Solution {
public:
// Good explanation written in notes
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nge; // map to store NGEs of all elements in num2
        stack<int> st;
        int n = nums2.size();

        // take nums 2 into consideration
        // Monotonically decreasing stack
        for(int i = n-1; i >= 0; i--){

            while( !st.empty() && nums2[i] >= st.top()){
                st.pop();
            }
            // at the end , all elements <= arr[i] is removed

            if(st.empty()) nge[nums2[i]] = -1;  // no GE

            else nge[nums2[i]] = st.top();

            st.push(nums2[i]); // compulsory push 
        }    

    
        // building and returning ans
        n = nums1.size();
        vector<int> ans(n);

        for(int i = 0; i < n ; i++){
            ans[i] = nge[nums1[i]];
        }

        return ans;
    }
};


/*
// This solution uses a monotonic decreasing stack to efficiently find the next greater element for each number in nums2.
// As we iterate through nums2, we maintain the stack and build a map of next greater elements, which we then use to answer queries from nums1.

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nextGreater;  // Stores the next greater element for each number in nums2
        stack<int> st;  // Monotonic decreasing stack

        // Traverse nums2 to fill nextGreater map
        for (int num : nums2) {
            // While current number is greater than stack top, it is the next greater for stack top
            while (!st.empty() && st.top() < num) {
                nextGreater[st.top()] = num;
                st.pop();
            }
            // Push current number to stack
            st.push(num);
        }

        // For remaining elements in stack, no next greater exists
        while (!st.empty()) {
            if (nextGreater.find(st.top()) == nextGreater.end()) {
                nextGreater[st.top()] = -1;
            }
            st.pop();
        }

        // Build result for nums1 using the map
        vector<int> ans;
        for (int num : nums1) {
            ans.push_back(nextGreater[num]);
        }

        return ans;
    }
};
*/