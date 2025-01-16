#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int diff = 0;
        for (int n : nums) {
            if (n < 10) diff += n;
            else diff -= n;
        }
        return diff != 0;
    }
};
