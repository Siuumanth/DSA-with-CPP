#include<iostream>
using namespace std;

int main(){

    int arr[]={1,2,3,4,5,6,7,8,9};
    cout<<"initial array \n";
int len =sizeof(arr)/4 -1;
    for(int i=0;i<=len;i++){
     cout<<arr[i];
    }
    cout<<endl;
int temp;
      for(int i=0;i<=len/2;i++){
       swap(arr[len-i ],arr[i]);   // or use temp variable 
    }
 cout<<"array after reversing \n";
    for(int i=0;i<=len;i++){
     cout<<arr[i];
    }

    

}