
// explanation given below

class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int n = arr.size();
        int low = 0, mid, high = n-1;
        int left, right;

        while(low<high){
            mid = low + (high-low)/2;

            if(mid == 0){
                right = arr[mid+1];
                left = INT_MIN;
            }
            else if(mid == n-1){
                left = arr[mid-1];
                right = INT_MIN;
            }
            else{
                left = arr[mid - 1];
                right = arr[mid + 1];
            }

            if(left < arr[mid] && arr[mid] > right){
                return mid;
            }
            
            // search space left
            if(left > arr[mid]){
                high = mid -1 ;
            }
            // search space right
            else if(arr[mid] < right){
                low = mid + 1;
            }
        }

        return low;
    }
};


/*
🧠 Analogy:
Think of the array as a mountain range. You’re hiking through it and can’t see the whole view — only your current position and one step left and right.

You always move towards the higher slope:

If the right side is higher, climb right.

If the left side is higher, climb left.

If you’re at a local peak, stop.

This "greedy climbing" with binary direction halves the search space each time — just like binary search.

*/