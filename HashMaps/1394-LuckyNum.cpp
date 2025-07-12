// 2 approaches that come in mind
// 1. Use a hash map and store the frequencies of each element and work with it 
// 2. Sort the array and its easy to count the frequencies 
class Solution {
public:
    int findLucky(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        int ans = -1 ; 
        int freq = 0;
        int cur = arr[0];

        for(int num : arr){
            if(cur == num){   // normally increment frequency
                freq++;
            }
            else{             // different element encountered
                if(cur == freq){
                    ans = max(freq, ans); // valid element found
                }

                freq = 1;             // invalid element
                cur = num;
            }
        }

        if( freq == arr.back() )
            ans = max(ans, freq);

        return ans;
        
    }
};

/*
Hash map approach 
unordered_map<int,int> mapp;
        for( int num: arr){
            mapp[num]++;
        }

        int ans = -1;

        for(int num : arr){
            if(num == mapp[num]){
                ans = max(ans, num);
            }
        }

        return ans;

    */