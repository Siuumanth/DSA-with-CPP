#include<stdio.h>
void main()
{
    int a[]={7,0,4,2,5,0,6,4,0,5},n=10,max,i,area=0,j=0,m;
    max=a[0];
    for(i=0;i<=n;i++)
    {
        if(a[i]>max)
            max=a[i];
    }
    area= max*n;
    for(i=0;i<n;i++)
    {
        area=area-a[i];
    }
    int air=0;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[j]>=a[i])
            {
                m=a[j];
                air=air+(max-a[i])*(j-i);
                i=j;
            }
            else if(j==n-1)
            {
                a[i]--;
                j=i;
            }    
        }
    }
    area=area-air;
    printf("Rainwater area is %d",area);
}
