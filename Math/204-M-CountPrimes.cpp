
// Sieve of eratosthenes

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> isPrime(n+1,true);  // array till n with all true 
        int count = 0, j = 0;
        for(int i = 2; i < n ; i++){
            if(isPrime[i] == true){
                for(j = i; j<n; j+=i){
                    isPrime[j] = false; 
                }
                count++;
            }
        }
        return count;
    }
};