#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t,n;
    cin>>t;
    
    for(int ti = 0; ti<t ; ti++){
        cin>>n;
        vector<int> nums(n);
        int fsum = 0,bsum = 0,valid = 0;
        for(int i = 0; i<n ; i++){
            cin>>nums[i];
            bsum += nums[i];
        }    
        for(int i = 0; i<n-1 ; i++){
            fsum += nums[i];
            bsum -= nums[i];
            if(fsum>=bsum) valid++;
        }
        cout<<valid<<endl;
    }
    return 0;
}
