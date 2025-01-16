#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool isSorted(vector<int> arr){
    for(int i = 0 ; i < arr.size() - 1;i++){
        if(arr[i]>arr[i+1]) return false;
    }
    return true;
}

int main() {
    int t;
    cin>>t;
    vector<int> kvalues(t);
    vector<int> nvalues(t);
    vector<vector<int>> arr(t);
    for(int i = 0;i<t;i++){
        cin>>nvalues[i];
        arr[i].resize(nvalues[i]);
        for(int j = 0;j<nvalues[i];j++){
            cin>>arr[i][j];
        }
    cin>>kvalues[i];
    }
    
  for(int i = 0;i<t;i++){      
    int k = kvalues[i];
    bool found = false;
    for(int j = 0;j< nvalues[i]- 2*k;j++)
    {
    if (isSorted ( vector<int> (arr[i].begin() + j, arr[i].begin() + j + k) ) ) {
        if (isSorted(vector<int>(arr[i].begin() + j + k, arr[i].begin() + j + 2 * k))) {
            cout << "true\n";
            found = true;
            break;
        }
    }

    }
    if(!found)
        cout<<"false\n";
  }    
    return 0;
}













