#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& aster) {
        sort(aster.begin(),aster.end());
        int end = aster.back();
        for(int rock : aster){
            if(mass > end) return true;
            if(rock <= mass) mass += rock;
            else return false;
        }
        return mass>=0;
    }
};