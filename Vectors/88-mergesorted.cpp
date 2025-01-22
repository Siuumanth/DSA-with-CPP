
#include<vector>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //2pointer approach, start from the ends
        int mp = m -1,np = n-1;
        int right = m+n-1;
        while(np>=0){
            if(mp>=0 && nums1[mp] > nums2[np]){
                nums1[right] = nums1[mp];
                mp--;
            }
            else{
                nums1[right] = nums2[np];
                np--;
            }
            right--;
        }
    }
};