#include<iostream>
using namespace std;

int main(){   
    for(int i = 20;i>0;i-=2){
        for(int j=0; j<i/2 + 1; j++){
            cout<<" "; 
        }
 for(int j=0; j<20-i + 1; j++){
            cout<<"*";
        }

cout<<"\n";
    }
}