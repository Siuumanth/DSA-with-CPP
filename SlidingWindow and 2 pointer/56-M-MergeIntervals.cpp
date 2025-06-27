
// Best solution: sort and merge using a different vector 
// While merging we check the overlapping sub intervals of different elements in s2


class Solution {
public:
    static bool d2sort(vector<int> a, vector<int> b){
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        // step 1: sort array 
        sort(arr.begin(), arr.end(), d2sort);

        int n = arr.size();

        vector<vector<int>> ans;
        int left, right;
        
        // step 2: merge
        for(int i = 0; i < n ;){
            left = arr[i][0];
            right = arr[i][1];

            while(i<n-1 && right >= arr[i+1][0] ){
                right = max(right, arr[i+1][1]);
                i++;
                cout<< right << endl;
            }

            ans.push_back({left,right});
            i++;
        }

        return ans;
    }
};