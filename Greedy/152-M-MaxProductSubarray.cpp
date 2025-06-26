
// Written in notes
class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int n = arr.size();
        
        int prefix = 1;
        int suffix = 1;
        int result = INT_MIN;
        
        for (int i = 0; i < n; i++) {

            // finding prefix sums 
            prefix *= arr[i];
            suffix *= arr[n - 1 - i];
            result = max(max(prefix,suffix), result);
            if(prefix == 0){
                prefix = 1;
            }
            if(suffix == 0){
                suffix = 1;
            }

            
        }

        return result;
    }
};




/*
// Written in notes

same method as before but simpler code
class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int n = arr.size();
        
        int prefix = 1;
        int suffix = 1;
        int result = INT_MIN;
        
        for (int i = 0; i < n; i++) {

        // finding prefix sums 
            prefix *= arr[i];
            result = max(prefix, result);
            if(prefix == 0){
                prefix = 1;
            }

            // finding suffix sums

            suffix *= arr[n - 1 - i];
            result = max(suffix,result);
            if(suffix == 0){
                suffix = 1;
            }
        }

        return result;
    }
};

*/