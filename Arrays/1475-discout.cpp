#include<iostream>
#include<vector>
#include<stack>
using namespace std;


// O(n2) approach
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> final(n);
        for(int i = 0 ;i < n; i++){
            int j;
            for( j = i+1 ;j < n; j++){
                if(prices[j]<=prices[i]){
                   final[i] = prices[i] - prices[j];
                   break;
                }
            }   
            if(j==n) final[i] = prices[i] ;
        }
        return final;
    }
};



// O(n) approach
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> result = prices;
        stack<int> stack;
        for(int i = 0 ;i < prices.size(); i++){
          while(!stack.empty() && prices[stack.top()] >= prices[i])
          {
            result[stack.top()] -= prices[i];
            stack.pop();
          }
           stack.push(i);
        }
     return result;
       
    }
   
};