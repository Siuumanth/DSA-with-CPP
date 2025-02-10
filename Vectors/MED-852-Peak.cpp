#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<unordered_map>
using namespace std;




class Solution {
    public:
        int peakIndexInMountainArray(vector<int>& arr) {
            int st = 1, end = arr.size() - 2,mid;  //as peak cant be 0 or n-1
            while(st <= end){
                mid = st + (end - st)/2;
                if(arr[mid-1] < arr[mid] && arr[mid+1] < arr[mid])
                  return mid;
                else if(arr[mid] > arr[mid -1])  // search right
                  st = mid + 1;
                else    // search left
                  end = mid - 1;  
                
            }
            return -1;
        }
    };
    
    
    // best way
    /*
    class Solution {
    public:
        int peakIndexInMountainArray(vector<int>& arr) {
            int st = 0, end = arr.size() - 1;
            while (st < end) {  // Notice `st < end` instead of `st <= end`
                int mid = st + (end - st) / 2;
                if (arr[mid] < arr[mid + 1])  
                    st = mid + 1;  // Peak is towards the right
                else if(arr[mid] > arr[mid + 1])
                    end = mid;  // Peak is at `mid` or towards the left
            }
            return st; // or return end; both are the same when loop exits
        }
    };
    */
    
    