#include<iostream>
using namespace std;

int main(){
    cout<<"Enter a number \n";
    int a;
    cin>>a;
    int c=0;
    for(int i = 2; i<a;i++){
if(a%i==0){
   c++;
}
    }

    if(c==0){
        cout<<a<<"\nIs a prime number";

    }
    else
    cout<<a<<"\nIs not a prime number";
}