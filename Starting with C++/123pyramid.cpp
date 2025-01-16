#include<iostream>
using namespace std;
int main(){
    int n=5;
  
    for(int i =1;i<n;i++){
        for(int j=0;j<(n-i);j++){
            cout<< " ";
     }
     int j;
    for( j=1;j<=i;j++){
            cout<<j;
     }
     
      for(int k=j-1;k>0 ;k--){
       if(k==i){
        continue;
       }
            cout<<k;
     }
     cout<<'\n';
    }
    return 0;
}