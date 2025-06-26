
class Solution {
public:
    int trap(vector<int>& arr) {

        stack<int> stak;
        int n = arr.size();
        int top, cur;

        int maxWater = 0, ans = 0;
        int topi;  

        for(int i = 0; i < n; i++){

            if(stk.empty()){
                stak.push(arr[i]);
                topi = i;
                continue;
            }

            top = stk.top();
            cur = arr[i];

            if( cur > top ){
                // trap rainwater
                maxWater += min(top, cur) * (i - topi); 
                stk.pop();
                maxWater = 0;
            }
            else if(cur <= top){
                // minus from ans
                maxWater -= cur;
            }
        }

        return ans;
    }
};