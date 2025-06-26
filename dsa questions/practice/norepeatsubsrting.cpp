using namespace std;
#include <iostream>
int main()
{
    string a,b="";
    int arr[100];
    cout<<"enter a string ";
    cin>>a;
    int i,j,k,c;
    for(i=0;i<a.length();i++)
    {
        b+=a[i];
        
        for(j=i;j<a.length();j++)
        {
            arr[i]=arr[i]+1; 
            if(a[i]==a[j])
            {
                c++;
                if(c>1)
                {
                    b="";
                    i=j-1;
                    break;
                }
                    
            }
        }
        
    }
    cout<<j;
    int max=arr[0];
    for(i=0;i<7;i++)
    {
        if(arr[i]>max)
            max=arr[i];
    }
    cout<<a.substr(i,arr[i]);

    return 0;
}