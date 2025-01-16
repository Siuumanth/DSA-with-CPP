//we have a sorted array, find a 2 sum in that

#include<iostream>
#include<vector>
using namespace std;

//Most optimal approach.... O(n)
int main(){
  vector<int> vec = {1,2,5,7,11,15,16};
  int n = vec.size();
  int ps,target = 9;  //ps = pairsum
  int i=0,j=n-1;
  while(i<j){
    ps = vec[i] + vec[j];
    if(ps>target)
      j--;
    else if(ps<target)  
      i++;
    else{
       cout<<" Asnwers are "<< vec[i] << " and " << vec[j];
       break;
    }
  }
    return 1;
}
