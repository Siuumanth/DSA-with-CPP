#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<unordered_map>
using namespace std;





// optimal approach with O(n) approach using hashmap
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        long int ans = 0;
        unordered_map<int,int> map;
        int temp;
        for (int t : time) {
            int temp = t % 60;
            map[temp]++;
        }
 // formula for combinations
        for (int i = 1; i < 30; i++) {
            if (map[i] > 0 && map[60 - i] > 0) {
                ans += map[i] * map[60 - i];
            }
        }

        if (map[0] > 1) {
            ans += (1LL *map[0] * (map[0] - 1)) / 2;
        }
        if (map[30] > 1) {
            ans += (1LL *map[30] * (map[30] - 1)) / 2;
        }
        return ans;
    }
};




//Brute force n2 approach 
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int ans = 0;
        int n = time.size();
        for(int i = 0 ; i<n; i++){
            for(int j = i+1; j< n; j++){
                if((time[i] + time[j]) % 60 == 0) ans++;
            }
        }
        return ans;
    }
};