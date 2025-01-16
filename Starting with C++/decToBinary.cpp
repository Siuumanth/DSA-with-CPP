#include<iostream>
#include<string>
using namespace std;


int convert(int n){
string ans = "";
int rem;
/*while(n>0){
 rem = n%2;
 cout<<"Rem is " << rem<<endl;
 n=n/2;
 ans =  ans + to_strṇing(rem);
 cout<<"Answer current is " << ans<<endl;
}*/
// OOOOOOOOOOOoRRRRRRRRRRRRRRRRR
int c=1;
int result =0;
while(n!=0){
    rem = n%2;
    n = n/2;
    result = result + (rem*(c));
    c=c*10;
}
return result;
}

int main(){
    int n;
    cout<<"Enter a number  ";
    cin>>n;
   cout<< " The binary is " << convert(n);

    return 0;
}

