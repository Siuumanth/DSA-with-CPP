using namespace std;
#include <iostream>
int main()
{
    string a,b="";
    cout<<"enter a string ";
    cin>>a;
    int i,j,k,c;
    for(i=0;i<a.length();i++)
    {
        c=0;
        for(j=i;j<a.length();j++)
        {
            if(a[i]==a[j])
            {
                c++;
                if(c>1)
                    break;
            }
        }
        if(c>1)
        break;
    }
    cout<<j;

    return 0;
}