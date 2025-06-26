#include<stdio.h>
void main()
{
    int n=9,a[20]={8,9,6,4,5,7,3,2,4},i,c=1,k1=1,k2=0;
    
    /*printf("enter number of elements");
    scanf("%d",&n);
    printf("enter elements\n");
    for(i=0;i<n;i++)
       scanf("%d",&a[i]);*/
    for(i=0;i<n;)
    {
        if(a[i]>a[i+1])
        {
            if(k1==k2)
            {
                i++;
                c++;
                k2++;
                continue;
            }
            if(k1>k2)
            {
                i++;
                c++;
                k2+=2;
                continue;
            }
            else
                i++;
        }        
        else if(a[i]<a[i+1])
        {
            if(k1==k2)
            {
                i++;
                c++;
                k1++;
                continue;
            }
            if(k2>k1)
            {
                i++;
                c++;
                k1+=2;
                continue;
            }
            else  
                i++;
        }
    }
    printf("%d",c);
}