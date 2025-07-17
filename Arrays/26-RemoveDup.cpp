
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;

        int j = 0;  

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[j]) {
                j++;
                nums[j] = nums[i];  
            }
        }

        return j + 1;  
    }
};

/*
// Unordered Set approach, for not sorted array
class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int n = arr.size();
        unordered_set<int> sett;
        int c = 0, j = 0;

        for(int i = 0; i < n; i++){
            if(sett.find(arr[i]) == sett.end()){  // first time element 
                arr[j] = arr[i];
                sett.insert(arr[i]);
                j++;
                c++;
            }
            // if element exists in list, do ntg
        }
        return c;
    }
};
*/