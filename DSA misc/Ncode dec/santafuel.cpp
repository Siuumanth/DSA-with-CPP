#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t,n;
    cin>>t;
    cin>>n;
    vector<vector<int>> fuels(t);
    vector<vector<int>> costs(t);
    for(int i = 0;i<t;i++)
    {
        fuels[i].resize(n);
        for(int j = 0;j<n;j++)
        {
            cin>>fuels[i][j];
        }
        costs[i].resize(n);
        for(int j = 0;j<n;j++)
        {
            cin>>costs[i][j];
        }
    }  
    //done accepting values
    
    //evaluating
    for(int i = 0; i<t ; i++)
    { 
        bool found = false;
        int j;
        for( j=0 ;j<n; j++)
        {
            int fuel = 0;
            int valid = true;
            for(int k=0; k<n; k++)
            {
                int station = (j+k) % n;
                fuel +=fuels[i][station];
                fuel -=costs[i][station];
                if(fuel<0)
                {
                    valid = false;
                    break;          
                }  
            }
            if(valid)
            {
               cout<< j <<"\n";
               found = true;
               break;
            } 
        }
        if(found == false){
            cout<<-1<<"\n";
        }  
    } 
    return 0;
}
