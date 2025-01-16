
#include<iostream>
using namespace std;

int main(){
    int n = 7;
    int arr[7] = {3,-4,5,4,-1,7,-8};
     
    int maxSum = -1335;
    int curSum  =  0; 

    for(int i =0; i<n; i++){
        curSum+=arr[i];
        maxSum = max(curSum,maxSum);
        if(curSum < 0){
            curSum = 0;
        }
    }
    cout<<"Maximum subarray sum = "<<maxSum;
    

    return 1;
}