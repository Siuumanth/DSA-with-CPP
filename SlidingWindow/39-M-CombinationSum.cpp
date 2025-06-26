class Solution {
public:
    
    void findComb(vector<int>& arr, int i,  int sum, int target, vector<int>& temp, vector<vector<int>>& ans){

         // base cases
        if( sum == target) {
            ans.push_back(temp);
            return;
        } 
        else if( sum > target) return; // or break  

        for(int j = i; j < arr.size(); j++){
            sum += arr[j];
            temp.push_back(arr[j]);
            findComb(arr, j, sum, target, temp, ans);  // U can also pass sum + arr[j]
                                                       // then u dont need to update sum
            temp.pop_back();  // backtracking
            sum -= arr[j];
        }

    }
    
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {

        sort(arr.begin(), arr.end());  // initialisation - sorting
        vector<vector<int>> ans;  // ans vector

        vector<int> temp; 

        findComb(arr, 0, 0, target, temp, ans);

        return ans;
    }
};
