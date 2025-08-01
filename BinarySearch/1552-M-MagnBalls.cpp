/*
Observations: 
- Binary search
- Find largest minimum magnetic force
- max magnetic force cannot be greater than max position of basket 

- Valid means try increasing 
- invalid means decrease it 
- In our O(n) function, we will:
pass in a minimum magnetic force, and keep placing balls untill the difference between intial and current element is above the mag force passed, else iterate over till its 
*/
class Solution {
public:
    bool isValid(vector<int>& arr, int m, int mid){
        int c = 1;
        int n = arr.size();
        int cur = arr[0];

        for(int i = 1; i < n ; i++){
            if(arr[i] - cur >= mid){
                c++;
                cur = arr[i];
            }
        }

        // if c < m, then placing is posisble, else lesser balls r needed so not possible
        return c >= m;
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        
        int n = position.size();
        int low = 0, mid;
        // ans cannot be higher than th max element 
        int high = position[n-1];

        int ans; // storing the last valid ans 

        while(low <= high){
            mid = low + (high-low)/2;
            if(isValid(position, m, mid)){
                // valid try to increase the ans
                ans = mid;
                low = mid+1;
            }
            else{   // invalid
            // decrease the ans 
                high = mid - 1;
            }
        }

        // converges at low = high
        return ans;
    }
};



// 1 2 3 4 5 1000000000