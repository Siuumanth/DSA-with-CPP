#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<unordered_map>
using namespace std;






//brute force, 2 pointer method O(m+n)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(),n = nums2.size();
        int len = m + n;
        vector<int> ans(len);
        int mp = 0, np = 0;
        for(int i = 0 ; i < len ; i++){
            if(np >= n || mp<m && nums1[mp] <= nums2[np]){
                ans[i] = nums1[mp];
                mp++;
            }
            else{
                ans[i] = nums2[np];
                np++;
            }
            
        } 
        if(len%2 == 0)
           return (ans[len/2] + ans[len/2 - 1]) / 2.0; 
        else 
           return ans[len/2];
    }
};