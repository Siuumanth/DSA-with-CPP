// 2 pointer 
// optimal solution
// get rid of set data structure
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        // in better approach we used to sort temp array and add to ans
        // here we will do reverse and sort the original array

        int n = arr.size(), sum;
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;

    // [-1,0,1,2,-1,-4] -> [-4,-1,-1,0,1,2]

        // to prevent duplicates, we skip over duplicate 
        for(int i = 0; i < n -2; ){
            int low = i + 1;
            int high = n - 1;   
            // 2 pointer approach to find the low and high(next 2 elements)
            
            while( low < high ){
                sum = arr[i] + arr[low] + arr[high] ;

                if(sum > 0) high--;  // decrease high and sum
                else if(sum < 0) low++;   // increase low and sum
                else{  // ans found
                    ans.push_back( {arr[i], arr[low], arr[high]} );

                    // loop till a proper condition is reached to avoid duplicates for low and high
                    while(low < n-1 && arr[low] == arr[low+1]) low++;
                    low++;

                    while(high > low && arr[high] == arr[high - 1]) high--;
                    high--;
                }
            }  

            // after the loop, we skip all the duplicate elements after i
            while(i < n-1 && arr[i] == arr[i+1]) i++;  
            i++; // mandatory increment

        }

        return ans;
    }
};


/*

[2, -3, 0, -2, -5, -5, -4, 1, 2, -2, 2, 0, 2, -4, 5, 5, -10] ->

[-10, -5, -5, -4, -4, -3, -2, -2, 0, 0, 1, 2, 2, 2, 2, 5, 5]




// 2 pointer 

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        int n = nums.size();
        sort(nums.begin(), nums.end());
        int k, j, sum;
        vector<vector<int>> ans;

        for(int i = 0; i < n; i++){
            // 2 pointer approach
            // to find 2 other pairs
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

*/


/*
Better approach using hash set, still gives TLE
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {

        int n = arr.size();
        set<vector<int>> sett; // final set to store all the ans

        // Method 1
        // We will use 2 loops for i and j, and iterate thru , and keep storing elements in between i and j in a set, and find 3rd element in that to avoid duplication

        for(int i = 0; i < n; i++){
            set<int> st;
            int k = i + 1;
            // to make sure we dont get duplicate indices
            for(int j = i+2; j < n; j++){
                st.insert(arr[k]);
                int find = -1 * (arr[i] + arr[j]);
                if(st.count(find)){
                    vector<int> temp = {arr[i], arr[j], find};
                    sort(temp.begin(), temp.end());
                    sett.insert(temp);
                }
                k++;
            }
        }
        // direct converstion from set to ans matrix 
        vector<vector<int>> ans(sett.begin(), sett.end());
        
        return ans;
    }
};
*/