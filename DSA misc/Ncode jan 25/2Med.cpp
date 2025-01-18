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
        vector<int> costs(n);
        for(int i = 0 ; i<n ; i++)
            cin>>costs[i];
        int maxProfit = 0;
        for(int i = 0 ; i<n-1 ; i++){
            if(costs[i]<costs[i+1]){
                maxProfit += costs[i+1] - costs[i];
            }
        }
        cout<<maxProfit<<endl;
    }
    return 0;
}
