class Solution {
public:
    int fib(int n) {
        if(n<=1) return n;

        int temp, f1 = 0, f2 = 1;
        
        for(int i = 2; i < n ; i++){
            temp = f1 + f2;
            f1 = f2;
            f2 = temp;  // shifting by 1
        }

        return f1+f2;

    }
};