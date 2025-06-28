
class Solution {
public:
    int numSubarraysWithSum(vector<int>& arr, int k) {
        int ans = 0, sum = 0;
        int n = arr.size();
        
        vector<int> PS(n);
        PS[0] = arr[0];
        for(int i = 1 ; i < n ; i++){
            PS[i] = PS[i-1] + arr[i];
        } 
        
        // now PS has all the prefix sums

        unordered_map<int,int> map;
        int val;

        // j is the right boundary
        // we fix j, and try to find i
        // in the map we store the frequencies of all PS-k upto j 

        map[0] = 1;  // to handle the case where prefix sum itself == k

        for(int j = 0; j<n ; j++){

            val = PS[j] - k;
        
            if(map.find(val) != map.end()){
                ans += map[val];      // if freq exists then add
            }
            
            map[PS[j]]++;
            
        }

        return ans;
    }
};