#include<iostream>
using namespace std;

int main(){
    int n = 5;
    int arr[10] = {3,-4,5,4,-1,7,-8};

    for(int st =0; st<n; st++){
        for(int end =0; end<n; end++){
            for(int i =st; i<=end; i++){
                  cout<<arr[i];
            }
            cout<<" ";
        }
        cout<<endl;
    }
    

    return 1;
}