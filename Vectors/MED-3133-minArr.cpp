
#include<vector>
using namespace std;
#include<iostream>

// best solution O(logn)
class Solution {
public:
    long long minEnd(int n, int x) {
        if(n==1) return x;
        n--;
        vector<short int> binx(64, 0); 
        vector<short int> binn(64, 0); 
        int ix = 0;
        int in = 0;
        int tempx = x;
        while (tempx != 0) {
            binx[ix] = tempx % 2;
            tempx /= 2;
            ix++;
        }
        int tempn = n;
        while (tempn != 0) {
            binn[in] = tempn % 2;
            tempn /= 2;
            in++;
        }
        int ix1 = ix;
        ix = 0;
        int i = 0;
        while (i < in ) { 
            if (binx[ix] == 0) {
                binx[ix] = binn[i];
                i++;
            }
            ix++;
        }
        ix+=1;
        ix = max(ix, ix1);
        long long ans = 0;
        for (int i = ix - 1; i >= 0; i--) 
            ans += (1LL<< i) * binx[i]; 
        return ans;
    }
};







//Medium brute force approach , gives Time limit exceeded
class Solution {
public:
    long long minEnd(int n, int x) {
        unsigned int ans = x;
        unsigned int temp = x;
        unsigned int i = 1;
        while(i<n){
            if((++temp & x) == x){
              ans = temp;  
              i++;
            }
        } 
     return ans;
    }
};












int main(){
    int x = 4, n = 2;
    if(n==1) return x;
        n--;
        vector<short int> binx(64, 0); 
        vector<short int> binn(64, 0); 
        int ix = 0;
        int in = 0;
        int tempx = x;

        while (tempx != 0) {
            binx[ix] = tempx % 2;
            tempx /= 2;
            ix++;
        }

        int tempn = n;
        while (tempn != 0) {
            binn[in] = tempn % 2;
            tempn /= 2;
            in++;
        }
        int ix1 = ix;
        ix = 0;
        int i = 0;
        while (i < in ) { 
            if (binx[ix] == 0) {
                binx[ix] = binn[i];
                i++;
            }
            ix++;
        }
        ix+=1;
        ix = max(ix, ix1);
        long long ans = 0;
        for (int i = ix - 1; i >= 0; i--) 
            ans = ans +  (1LL<< i) * binx[i];  
        //print binx
        for (int i = 0; i < 7; i++)
            cout << binx[i] << " ";
        cout<<"\n"<<ix;
}
