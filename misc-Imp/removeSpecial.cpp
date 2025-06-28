#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

int main(){
    string s = "thw$ g##bjhwd vgf*gh$vvdd#bduhc";
    int n = s.length();

    unordered_set<char> set = {'$', '*', '#'};

    int c = 0;
    int valid = 0; 
    string ans = "";

    for(int i = 0; i<n;){ 
        c=0, valid = 0;

        if(set.find(s[i]) != set.end()) {
            c++;
        }
        else{
            ans += s[i];   // valid character
        }

        i++;
        while(valid != c && i<n){
            if(set.find(s[i]) != set.end()){
                c++;
            }
            else if(s[i] == ' '){
                ans += s[i];
                i++;
                continue;
            }
            else{   // valid character
                valid++;
            }
            i++;
        }

    }

    cout<< ans;


    return 0;
}

// git commit -m " Did 496 1199 and smarthire string problem in miscImp"