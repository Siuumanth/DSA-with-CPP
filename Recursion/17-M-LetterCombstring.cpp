class Solution {
public:
    void getAns(const string& st, vector<string>& ans, string temp, unordered_map<char, string> mapp, int i){
        // base case
        if(i >= st.size()){
            // include ans
            ans.push_back(temp);
            return;
        }

        // actual recursion
        // choose 1 index , for each index and combination
        for(int j = 0; j < mapp[st[i]].size(); j++){
            temp.push_back(mapp[st[i]][j]);

            getAns(st, ans, temp, mapp, i+1);

            temp.pop_back();  // backtrack

        }

    }


    vector<string> letterCombinations(string st) {
        if(st == "") return {};
        unordered_map<char, string> mapp;
        mapp['2'] = "abc";
        mapp['3'] = "def";
        mapp['4'] = "ghi";
        mapp['5'] = "jkl";
        mapp['6'] = "mno";
        mapp['7'] = "pqrs";
        mapp['8'] = "tuv";
        mapp['9'] = "wxyz";

        vector<string> ans;

        getAns(st, ans, "", mapp, 0);

        return ans;
    }
};