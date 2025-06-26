
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& arr, int k) {

        // first we find no. of valid subarrays for <=k
        // then find for <= k - 1
        // difference is our answer
        // explanation written in notes

        /// ExactlyK(arr,k) = AtMostK(arr,k) − AtMostK(arr,k−1)

        int ans = func(arr, k) - func(arr, k - 1);

        return ans;
        
    }

    // function to find valid subarrays with distinct integers <= k
    int func(vector<int> &arr, int k){
        int n = arr.size();
        int count = 0, left = 0, right;
        unordered_map<int, int> mapp;  // to store { ele: freq }

        for(right = 0; right < n; right++){
            mapp[ arr[right] ]++;

            while(mapp.size() > k){
                mapp[ arr[left] ]--;

                if(mapp[ arr[left] ] == 0)
                    mapp.erase( arr[left] );

                left++;
            }
            count += right - left + 1;   // track no. of possible subarrays for each valid window(written in notes)
        }
        return count;

    }
};

/*
    Intuition:
    To count subarrays with exactly K distinct integers, we use the idea that:
    - Subarrays with exactly K distinct = Subarrays with at most K distinct - Subarrays with at most (K - 1) distinct.
    This works because "at most K" includes all subarrays with 1, 2, ..., K distinct integers. 
    Subtracting "at most K-1" removes all subarrays with fewer than K distinct integers,
    leaving us with only the ones having exactly K.

    We use a sliding window + hashmap approach to count subarrays with at most K distinct elements efficiently.
*/
