#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<unordered_map>
using namespace std;



// Brute force approach - all possible containers
class Solution {
public:
    int maxArea(vector<int>& height) {
        int temp , area = 0;
        for(int i = 0; i < height.size(); i++){
            for(int j = i+1; j < height.size(); j++){
                temp = min(height[i],height[j]);
                temp = temp * (j-i);
                if(area<temp)
                   area = temp;
            }
        }
        return area;
    }
};


//O(n) 2pointer approach
class Solution {
public:
    int maxArea(vector<int>& ht) {
        int curWater , maxWater = 0;
        int left = 0, right = ht.size() - 1;
        while(right>left){
            int temp = min(ht[left],ht[right]);
            curWater = temp * (right - left);
            maxWater = max(curWater, maxWater);

            ht[left] < ht[right] ? left++ : right--;
        }
        return maxWater;
    }
};


