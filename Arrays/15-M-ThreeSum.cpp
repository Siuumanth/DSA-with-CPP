
// 2 pointer 

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        int n = nums.size();
        sort(nums.begin(), nums.end());
        int k, j, sum;
        vector<vector<int>> ans;

        for(int i = 0; i < n; i++){
           j = i + 1;
           k = n - 1;

           if( i>0 && nums[i] == nums[i-1]){    // to avoid duplicate triplets from i 
              continue; 
           }

           while(j<k){

              sum = nums[i] + nums[j] + nums[k];

              if(sum > 0)  k--;   // sum too big

              else if( sum < 0) j++;  // sum too small

              else if(sum == 0){
                  // triplet found
                  ans.push_back( { nums[i], nums[j], nums[k] } );
                  j++;
                  k--;
                  
                  while( j < k && nums[j] == nums[j-1])  j++; // make sure we dont get dupl nums[j]
              }
              
           }
        }
        
        return ans;
    }
};