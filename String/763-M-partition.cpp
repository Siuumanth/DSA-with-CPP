class Solution {
public:

    vector<int> partitionLabels(string s) {
        // Most optimal approach, using 2 pointer 

        vector<int> last(26); // store last occurances of each character 
        int n = s.size();
        for (int i = 0; i < n; i++) {
            last[s[i] - 'a'] = i;
        }

        vector<int> ans;
        int start = 0, end = 0;  // start and end are 2 pointers
        for(int i = 0; i<n; i++){
            end = max(end, last[s[i] - 'a']);  // end has the largest last index

            if(i == end){  // converges, means optimal interval found
                ans.push_back(end - start + 1);
                start = i+1;
            }
        }

        return ans;
    }
};

/*
Approach 1: not that efficient but works, uses merging overlapping subintervals 
// Uses merging sub intervals 
class Solution {
public:
static bool d2sort(vector<int> a, vector<int> b){
        return a[0] < b[0];
    }
    vector<int> partitionLabels(string s) {
        // Step 1: store the first and last occurence of each character
        vector<vector<int>> arr;

        int n = s.length();
        for(int i = 0; i < 26; i++){
            char cur = 'a' + i;
            int first = INT_MAX, last = -1;
            for(int j = 0; j<n; j++){
                if(s[j] == cur){
                    first = min(first, j);
                    last = max(last, j);
                }
            }
            if(last == -1) continue;  // character not present
            arr.push_back({first, last});
        }

        // now intervals has all first and last occurances of each alphabet

        // Step 2: Merge sub intervals
        sort(arr.begin(), arr.end(), d2sort);

        n = arr.size();
        vector<int> ans;
 
        // Now merging overlapping sub intervals and storing differences
        for(int i = 0; i < n; ){
            int first = arr[i][0];
            int last = arr[i][1];
            while(i<n-1 && last >= arr[i+1][0]){
                last = max(last, arr[i+1][1]);
                i++;
            }
            ans.push_back(last - first + 1);
            i++;
        }

        return ans;
        
    }
};
*/