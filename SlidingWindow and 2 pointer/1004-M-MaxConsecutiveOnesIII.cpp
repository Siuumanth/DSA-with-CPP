
class Solution {
public:
    int longestOnes(vector<int>& arr, int k) {
        int n = arr.size();
        int left = 0, right;
        int ans = 0, count = 0;


        for(int right = 0; right < n; right++){
            if( arr[right] == 1){
                count++;
            } else {
                k--;
                count++;
            }

            while(k<0){
                if(arr[left] == 0){
                    k++;
                }
                left++;
                count--;
            }

            ans = max(ans, count);

        }

        return ans; 
    }
};