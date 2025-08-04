class Solution {
public:
    // Recursion + backtracking
    void findStrings(int n, vector<string>& ans, string& s, int left, int right){
        // base cases
        if(s.size() == n){
            ans.push_back(s);
            return;
        }
        
        // try out all possibilities
        // you can place opening bracket anywhere you want
        if(left > 0){
            s.push_back('(');
            findStrings(n, ans, s, left-1, right);
            s.pop_back();
        }

        // you can only place closing bracket when the number of opening bracket is greater than closing bracket
        if(right > left ){   // necessary rule 
            s.push_back(')');
            findStrings(n, ans, s, left, right-1);
            s.pop_back();
        }
    }



    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        // No. of opening and closing paranthesis we have is n

        string s = "(";    // initial condition

        findStrings(n * 2, ans, s, n-1, n);  // total n = n * 2

        return ans;
        
    }
};