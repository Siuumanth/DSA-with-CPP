#include<vector>
#include<stack>

using namespace std;

class Solution {
public:
    // Using monotonic stack
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();

        vector<int> nle(n);  // next lesser elements
        vector<int> ple(n);  // previous lesser elements
        stack<int> st;
  
        // 1. Next lesser element : monotonically increasing stack
        for(int i = n-1; i>=0; i--){
            while(!st.empty() && arr[i] <= arr[st.top()] ){
                st.pop();
            }

            if(st.empty()) nle[i] = n; // no smaller to the right
            else nle[i] = st.top();   // next lesser element towards left

            st.push(i);
        }

        // clear stack
        while (!st.empty()) st.pop();

        // 2. Previous lesser element : monotonically decreasing stack
        for(int i = 0 ; i<n; i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }

            if(st.empty()) ple[i] = -1;
            else ple[i] = st.top();

            st.push(i);
        }

        // 3. finding answer by formula
        // We will assume every element as minimum and find subarrays for that
 
        long long ans = 0;
        int mod = 1e9 + 7;
        int left, right;

        /*
        left = i - ple[i];       // choices on the left (how far you can expand)
        right = nle[i] - i;      // choices on the right
        count = left * right     // total subarrays where arr[i] is the min
        */
        
        for (int i = 0; i < n; i++) {
            left = i - ple[i];
            right = nle[i] - i;
        
            long long contrib = (1LL * arr[i] * left % mod) * right % mod;
            ans = (ans + contrib) % mod;
        }
        
        return ans;
        
    }
};

/*
class Solution {

public:
    // Brute force approach, go through each subarray
    int sumSubarrayMins(vector<int>& arr) {
        long long ans = 0; 
        int n = arr.size();
        
        for(int i = 0; i < n; i++){
            int minEle = arr[i];
            for(int j = i; j < n; j++){
                minEle = min(minEle, arr[j]);
                ans += minEle;
            }
        }

        int MOD = 1000000007;
        int final = ans % MOD;
        
        return final;

    }
};
*/