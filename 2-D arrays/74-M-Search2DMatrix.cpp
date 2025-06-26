
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int low = 0, high = m * n - 1;
        
        int mid;
        int a,b;
        int ele;

        
        while(low <= high){
            mid = low + (high-low)/2;
            
            a = mid/n;
            b = mid % n;
            
            ele = matrix[a][b];

            if( ele == target){
                return true;
            }

            if(ele > target){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return false;
    }
};