// Solving in logn Complexity:  
// No. of elements missing before arr[i] = arr[i] - i - 1
// so
// ans = if k >= mid && 

class Solution {
    // explanation and derivation given in NB
public:
    int findKthPositive(vector<int>& arr, int k) {

        int missing, n = arr.size();
        int low = 0, high = n-1, mid;

        while(low <= high){
            mid = (low + high)/2;
            missing = arr[mid] - mid - 1;

            if(missing < k) low = mid+1;
            else if(missing >= k) high = mid - 1;
        }

        // now, nearby terms will be at high and low , loop ends when high < low, so high - 1 = low

        return high + 1 + k; // or low + k
        
    }
};