#include<iostream>
#include <vector>
using namespace std;    

void printSubsets(vector<int>& arr, vector<int>& ans,int i) {
    if(i == arr.size()) {
        for(int j = 0; j < ans.size(); j++) {
            cout << ans[j] << " ";
        }
        cout << endl;
        return;
    }
    
    ans.push_back(arr[i]);    // including ith element
    printSubsets(arr, ans, i+1);

    ans.pop_back();            // excluding ith element
    printSubsets(arr, ans, i+1);
}

int main(){
    
    vector<int> arr = {1,2,3,4};
    vector<int> ans;
    printSubsets(arr, ans, 0);

    return 1;
}