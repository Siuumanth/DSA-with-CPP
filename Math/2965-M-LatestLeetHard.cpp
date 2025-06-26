
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> ans;
        unordered_set<int> s;
        int n = grid.size();
        int a,b;
        // a = repeated value, b = missing value 
        
        int expSum = 0, actualSum = 0;

        // for finding repeated, we use a simple set
        for(int i = 0; i < n; i++){
            for(int j = 0; j<n; j++){
                actualSum += grid[i][j];

                if(s.find(grid[i][j]) != s.end()){
                    a = grid[i][j];
                    ans.push_back(a);
                }

                s.insert(grid[i][j]);
            }
        }
        // for finding missing value, we can make use of sum of n numbers till n2
        // with formula, we get the expected sum from 1 to n2
        // expectedSum + a - b = actual sum

        expSum = ((n*n) * (n*n + 1))/2;
        b = expSum + a - actualSum;
        ans.push_back(b);

        return ans; 
    }
};