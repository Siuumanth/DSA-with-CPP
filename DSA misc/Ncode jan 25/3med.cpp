#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t;
    cin>>t;
    vector<int> parades(t);
    vector<int> averages(t);
    for(int ti = 0; ti<t ; ti++){
        cin>>parades[ti];
    }
    for(int ti = 0; ti<t ; ti++){
        int n = parades[ti];
        vector<int> arr(n);
        arr[0] = n;
        for(int i = 1 ; i <= n ; i++)
            arr[i] = i;
        int avgs = 0;
        for(int i = 0; i<n-3 ; i+=3){
            avgs += (arr[i] + arr[i+1] + arr[i+2])/3;
        }
        cout<<avgs<<endl;
    }
    
    return 0;
}
