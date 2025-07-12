//         4   6    8
// 5 6 7 7 8 9 9 9 10
// n = 9

class Solution {
public:
    vector<int> searchRange(vector<int>& arr, int target) {
        int n = arr.size();

        int first = -1, last = -1;
        int low = 0, high = n - 1;
        int mid;

        // first position
        while(low <= high){
            mid = low + (high - low)/2;

            if(arr[mid] == target){
                if(mid == 0 || arr[mid-1] != target){  // condition for first
                    first = mid;
                    break;
                }
                else{
                    high = mid - 1;
                }
            }

            else if ( target > arr[mid]){
                low = mid + 1; 
            }
            else high = mid - 1;
        }


        // last position
        low = 0, high = n - 1;

        while(low <= high){
            mid = low + (high - low)/2;

            if(arr[mid] == target){
                if( mid == n-1 || arr[mid + 1] != target){  // condition for last
                    last = mid;
                    break;
                }
                else{
                    low = mid + 1;
                }
            }

            else if ( target > arr[mid]){
                low = mid + 1; 
            }
            else high = mid - 1;
        }

        return {first, last};

    }
};