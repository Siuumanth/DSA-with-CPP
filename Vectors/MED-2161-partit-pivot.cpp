


#include<vector>
using namespace std;

class Solution {
    public:
        vector<int> pivotArray(vector<int>& nums, int pivot) {
            vector<int> lesser;
            vector<int> greater;
            vector<int> same;
    
            int n = nums.size();
    
            for(int num : nums){
                if(num < pivot) lesser.push_back(num);
                else if ( num>pivot) greater.push_back(num);
                else same.push_back(num);
            }
            lesser.insert(lesser.end(), same.begin(), same.end());
            lesser.insert(lesser.end(), greater.begin(), greater.end());
    
            return lesser;
        }
    };