#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<unordered_map>
using namespace std;


class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int xorValue  = nums1[0];
        for(int i = 1; i<nums1.size(); i++){
            xorValue = xorValue^nums1[i];
        }
        int xorTemp = xorValue;
        if(nums1.size() % 2 == 0 && nums2.size()%2 == 0)
          return 0; // both even

        else if(nums1.size()%2 ==1 && nums2.size()%2 ==0){
            xorValue = nums2[0];
            for(int i = 1; i<nums2.size(); i++) 
                xorValue = xorValue ^ nums2[i];
            return xorValue;  //1st is odd
        }
        else if(nums1.size()%2 ==0 && nums2.size()%2 ==1){
            return xorValue;  //2nd is odd
        }
        
        for(int i =0; i<nums2.size(); i++){
                xorValue = xorValue ^ nums2[i];
            }
        return xorValue;  // both are odd
    }
};

