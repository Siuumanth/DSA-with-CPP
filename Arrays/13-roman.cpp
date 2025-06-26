#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;



int getNum(char ch){
    switch(ch){
    case 'I': return 1;
    case 'V': return 5;
    case 'X': return 10;
    case 'L': return 50;
    case 'C': return 100;
    case 'D': return 500;
    case 'M': return 1000;
    default: return 0;
    }
}

class Solution {
public:
    int romanToInt(string roman) {
        int result = 0;
        
        for( int i = 0; i < roman.size(); i++){
            if(getNum(roman[i])<getNum(roman[i+1])){
             result += getNum(roman[i+1]) - getNum(roman[i]);
             i++;
            }
            else{
              result += getNum(roman[i]);
            }
            if(i+1==roman.size()){
                break;
            }
        }
        return result;
    }
};


