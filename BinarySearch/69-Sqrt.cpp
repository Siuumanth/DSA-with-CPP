class Solution {
public:
    int mySqrt(int n) {

        if( n==0 || n  == 1) return n;

        int low = 0, high = n;
        int mid;
        int ans = 0;

        while(low < high){
            mid = low + (high-low)/2;
            long long sqr = 1LL * mid * mid;

            if(sqr == n) return mid;

            // search space left
            if( sqr > n){
                high = mid - 1;
            }

            // search space right
            if( sqr < n){
                low = mid + 1;
            }
        }

        if( 1LL * low * low > 1LL * n) return low - 1;
        // or u can just add while(low <= high), and keep an ans = mid variable to omit this line

        return low;
    }

};