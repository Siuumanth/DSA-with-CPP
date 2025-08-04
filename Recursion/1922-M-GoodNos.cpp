/*
Even indices - even
Odd indices - prime
*/
class Solution {
public:
    const int MOD = 1e9 + 7;

    // COrret way to power large numbers and mod it 
// recursive way to safely power large numbers
    long long modpow(int base, long long exp) {
        if (exp == 0) return 1;

        long long half = modpow(base, exp / 2);
        long long res = (half * half) % MOD;
    
        if (exp % 2 == 1)
            res = (res * base) % MOD;
    
        return res;
    }

    int countGoodNumbers(long long n) {
        long long evenCount = (n + 1) / 2;  // indices: 0, 2, 4,...
        long long oddCount = n / 2;         // indices: 1, 3, 5,...

        long long ans = (modpow(5, evenCount) * modpow(4, oddCount)) % MOD;
        return (int)ans;
    }
};



/*
// works but using math to do powers
  long long modpow(long long base, long long exp, int MOD) {
        long long result = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2) result = (result * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return result;
    }

    int countGoodNumbers(long long n) {
        long long evenCount = (n + 1) / 2;  // indices: 0, 2, 4,...
        long long oddCount = n / 2;         // indices: 1, 3, 5,...

        long long ans = (modpow(5, evenCount, MOD) * modpow(4, oddCount, MOD)) % MOD;
        return (int)ans;
    }

    */
