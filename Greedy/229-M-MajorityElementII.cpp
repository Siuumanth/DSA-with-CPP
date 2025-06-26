
class Solution {
public:
    vector<int> majorityElement(vector<int>& arr) {
        int n = arr.size();
        int c1 = 0, c2 = 0;
        int el1 = INT_MIN;
        int el2 = INT_MIN;

        for(int i = 0; i<n; i++){
            if(c1 == 0 && arr[i] != el2){
                c1 = 1;
                el1 = arr[i];
            }
            else if( c2 == 0 && arr[i] != el1){
                c2 = 1;
                el2 = arr[i];
            }
            else if( arr[i] == el1){
                c1++;
            }
            else if( arr[i] == el2){
                c2++;
            }
            else{
                c1--;
                c2--;
            }
        }

        // Now that we have the elements , for the last step we will manually check if the answers are valid or not

        int limit = n/3;
        c1 = 0, c2 = 0;
        vector<int> ans;

        for(int i = 0; i<n; i++){
            if(arr[i] == el1) c1++;
            else if(arr[i] == el2) c2++;
        }

        if(c1>limit) ans.push_back(el1);
        if(c2>limit) ans.push_back(el2);

        return ans;
    }
};

/*O(nlogn) approach, sort and traverse
class Solution {
public:
    vector<int> majorityElement(vector<int>& arr) {
        vector<int> ans;
        int n = arr.size();
        int limit = n/3;
        int c = 0;
        int cur = arr[0];
        int temp;

        sort(arr.begin(), arr.end());

        for(int i = 0; i<n ; i++){
            if(c==0) cur = arr[i];
            if(cur == arr[i]){
               c++;
            }
            if(c > limit){
                ans.push_back(cur);
                c=0;
                while(i+1 < n && arr[i+1] == cur){
                    i++;
                }
            }
            if (cur != arr[i]){
                cur = arr[i];
                c = 1;
            }
        }
        return ans;
    }
};
*/