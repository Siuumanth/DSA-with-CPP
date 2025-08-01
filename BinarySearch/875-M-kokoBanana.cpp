class Solution {
public:
    bool possibleToEat(int mid, vector<int>& arr, int h){
        // arr is already sorted
        // so follow a greedy approach and eat all bananas from start
        int c = 0;  // will store the hours needed to eat bananas 

        for(int i = 0; i < arr.size() ; i++){
            c += arr[i] / mid;   // eat that pile consuming hours 
            if(arr[i] % mid > 0) c++;   // consume extra hour
        }
        // if c < h valid, else if c > h then invalid 
        return c <= h;
    }
 
    int minEatingSpeed(vector<int>& piles, int h) {
        // Binary search
        // limit is between 1 and max element
        int low = 1, mid;
        int high = *max_element(piles.begin(), piles.end());

        // max ans, len = max(piles) or arr[last]
        while(low < high){
            mid = low + (high - low) / 2;
            if(possibleToEat(mid, piles, h)){
                // try a smaller ans 
                high = mid;   // mid can be the best ans so dont do high = mid - 1
            }
            else {  // invalid 
                // try higher ans
                low = mid + 1;
            }
        }

        // low will have the valid ans
        return low;
        
    }
};

// sorted = 4 11 20 23 30  h = 6
// n = 30