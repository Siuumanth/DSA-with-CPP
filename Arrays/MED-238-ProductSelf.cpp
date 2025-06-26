#include<vector>
using namespace std;

//O(n) approach
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int temp = 1;
        ans[0] = temp;
        // for prefix
        for(int i = 1; i < n;i++){
          temp *= nums[i-1];
          ans[i] = temp;
        }
        // for suffix
        temp = 1;
        for(int i = n-2; i >= 0;i--){
          temp *= nums[i+1];
          ans[i] *= temp;
        }
        return ans;
    }
};