#include<stdio.h>
#include<conio.h>
void main()
{
    int target;
    printf("enter number");
    int i,j;
    scanf("%d",&target);
    int nums[]={2,7,11,15};
    for(i=0;i<(sizeof(nums) / sizeof(nums[0]));i++)
    {
        for(j=0;j<(sizeof(nums) / sizeof(nums[0]));j++)
        {
            if(nums[i]+nums[j]==target)
            {
                printf("[%d,%d]",i,j);
            }

        
        }
        
    }
    getch();
}