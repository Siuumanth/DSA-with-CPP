
// Optimal approach, TC O(n) and SC O(n)
// PS formula: SubArrSum(i,j) = PS[j] - PS[i]
// PS[i-1] = PS[j] - k;

// Final approach, not using seprate array for PS
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixCount;
        prefixCount[0] = 1; // Base case: one subarray with sum 0 before any elements

        int sum = 0, count = 0;

        for (int num : nums) {
            sum += num; // Update running prefix sum

            // Check if there's a prefix sum that makes the current subarray sum = k
            if (prefixCount.find(sum - k) != prefixCount.end()) {
                count += prefixCount[sum - k]; // Add all such subarrays
            }

            // Record current prefix sum in map
            prefixCount[sum]++;
        }

        return count;
    }
};


/*
The folowing is same as the discussed approach , but uses an extra array for PS
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefixSum(n);   // Prefix sum array
        int count = 0;
        unordered_map<int,int> map;
        int val;
        
        prefixSum[0] = nums[0];
        for( int i = 1; i < n; i++){
            prefixSum[i] = prefixSum[i-1] + nums[i];
        }

        // Now prefixSum has all the prefix sums 
        
        
        for(int j = 0; j<n ; j++){
            if(prefixSum[j] == k) count++;
            
            val = prefixSum[j] - k;  
            if(map.find(val) != map.end()){      // PS already exists in map
                count += map[val];
            }

            if(map.find(val) == map.end()){     // PS doesnt exist in map
                map[prefixSum[j]] = 0;  
            }

            // Update the map with current prefix sum
            map[prefixSum[j]]++;             
        }

        return count;
    }
};
*/


/*
// Brute force - O(n2) approach
// We check the possible sums of all contiguous subarrays 
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0, ans = 0;
        for( int i = 0;i < n ; i++){
            sum = nums[i];
            for( int j = i + 1; j<n; j++){
                if(sum == k){
                    ans++;
                }
                sum += nums[j];
            }
            if(sum == k){
                    ans++;
                }
        }
        return ans;
    }
};
*/