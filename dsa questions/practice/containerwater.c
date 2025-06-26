#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<conio.h>
int minimum(int a,int b)
{
    if(a<b)
       return a;
    else
       return b;
}
void main()
{
    int n=9,a[20]={1,8,6,2,5,4,8,3,7},m[20],i,j,water;
    /*printf("enter number of elements");
    scanf("%d",&n);
    printf("enter elements");
    for(i=0;i<n;i++)
       scanf("%d",&a[i]);*/
    //m[0]=a[0]*a[0];
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if((minimum(a[i],a[j])*(abs(i-j)))>m[i])
            {
                m[i]=minimum(a[i],a[j])*(abs(i-j));

            }
        }
    }
    printf("%d",m[i]);

    water=m[i];
    for(int i=0;i<n;i++)
    {
        if(m[i]>water)
           water=m[i];
    }      
    printf("Highest paani is %d",water);
    getch();
}
