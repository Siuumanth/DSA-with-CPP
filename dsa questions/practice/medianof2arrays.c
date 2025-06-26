#include<stdio.h>
#include<conio.h>
void main()
{
    int n1,n2,a1[10],a2[10],i,j,b[20],c=0,med;
    printf("enter number of elements in 1st array");
    scanf("%d",&n1);
    printf("enter elements \n");
    for(i=0;i<n1;i++)
        scanf("%d",&a1[i]);
    printf("enter number of elements in 2nd array");
    scanf("%d",&n2);
    printf("enter elements\n");
    for(i=0;i<n2;i++)
       scanf("%d",&a2[i]);
    for(i=0;i<n1+n2;i++)
    {
        if(i>=n1)
        {
            
            b[i]=a2[c];
            c++;
        }
        else 
            b[i]=a1[i];
    }
    for(i=0;i<n1+n2;i++)
        printf("%d \t",b[i]);
    
    if((n1+n2)%2==0)
    {
        int m=(n1+n2)/2;
        med=(b[m]=b[m+1])/2;
    }
    else{
        med=((n1+n2)/2)+1;
    }
    printf("MEDIAN IS %d",med);
    getch();
}


