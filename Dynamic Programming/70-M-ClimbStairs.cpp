class Solution {
public:

    int climbStairs(int n) {

        // In the DP approach, if u calculate ans for 1,2,3,4,5....
        // U will find that they all resemble the fibonacci sequence
        // So we need to return ans of Climb(n-1) + Climb(n-2)

        int temp, f1 = 0, f2 = 1;
        
        for(int i = 1; i < n ; i++){
            temp = f1 + f2;
            f1 = f2;
            f2 = temp;  // shifting by 1
        }

        return f1+f2;
    }

   
};


/*

O(2^n) solution, using backtracking
Gives TLE - really inefficient

class Solution {
public:
    int climbStairs(int n) {
        int ans = 0;
        climbIt(n, 0, ans);

        return ans;
    }

    void climbIt(int n, int count, int &ans){
        if(count == n){
            ans++;
            return;
        }
        else if(count > n){
            return;
        }

        for(int i = 1; i < 3; i++){
            climbIt(n, count + i, ans);
        }

        return;

    }
};
*/