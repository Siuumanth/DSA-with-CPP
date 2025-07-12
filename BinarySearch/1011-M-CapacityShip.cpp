
/*
Approach : Binary search 
So the idea behind this approach is to binary search on the capacity of the ship — we’re not searching for an element, we’re searching for the minimum possible weight the ship needs to carry to finish shipping all the packages in D days. 

For any given capacity, we simulate the process: we try to load packages in order without exceeding that capacity in a single day.

If the total number of days required with that capacity is more than D, then the capacity is too low — so we search higher. 

Otherwise, we try to lower it. Since the number of days required decreases as the capacity increases, this forms a monotonic function, which makes binary search ideal for narrowing down to the minimal valid capacity.
*/


class Solution {
public:

    bool isValidCapacity(vector<int>& arr, int limit, int days){
        int sum = 0;
        int ans = 0;
        int n = arr.size();

        for(int i = 0; i < n; i++){
            if(arr[i] > limit) return false;  // limit exceed
            sum += arr[i];
            if(sum > limit){
                ans++;
                sum = arr[i];
            }
        }

        if(arr[n-1] <= limit) ans++;

        // ans < days => valid  , capacity enuf, can go lower
        // ans > days => invalid, too low, need higher capacity

        return ans <= days;
    }


    int shipWithinDays(vector<int>& arr, int days) {
        int n = arr.size();

        // 1. Store sum
        int sum = accumulate(arr.begin(), arr.end(), 0);

        int low = *max_element(w.begin(), w.end()) , high = sum;
        int mid;

        while(low < high){
            mid = (low + high)/2;

            if(isValidCapacity(arr, mid, days)){
                high = mid;
            }
            else{
                low = mid + 1;
            }
        }

        return low;
    }
};