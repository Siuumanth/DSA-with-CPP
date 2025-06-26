//we are reusing the sum calculated in the previous sums
// we can reduce complexity from n3 to n2

// this is brute force

#include<iostream>
using namespace std;

int main(){
    int n = 7;
    int arr[10] = {3,-4,5,4,-1,7,-8};
     
    int maxSum = -1335;

    for(int st =0; st<n; st++){
        int curSum  =  0;
        for(int end =st; end<n; end++){
            curSum += arr[end];
            maxSum = max(curSum,maxSum);
        }
    }
    cout<<"Maximum subarray sum = "<<maxSum;
    

    return 1;
}