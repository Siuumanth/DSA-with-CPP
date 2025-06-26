#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int maximumBags(vector<int>& C, vector<int>& R, int e) {
        int ans = 0;
        for(int i = 0; i < R.size() ; i++) R[i] = C[i] - R[i];
        sort(R.begin(),R.end());
        for(int i = 0; i < R.size() && R[i] - e <=0 ; i++){
            ans++;
            e-=R[i];
        }
        return ans;
    }
};