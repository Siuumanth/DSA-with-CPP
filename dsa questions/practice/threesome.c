#include<stdio.h>
void main()
{
    int a[6]={-1,0,1,2,-1,-4},n=6;
    int i,j,k,sum;
    for(i=0;i<n;i++)
    {
        for(j=i;j<n;j++)
        {
            for(k=j;k<n;k++)
            {
                if(a[i]!=a[j] && a[j]!=a[k] && a[k]!=a[i])
                {
                    
                    if(a[i]+a[j]+a[k]==0)
                    {
                        printf("[%d,%d,%d]\n",a[i],a[j],a[k]);
                
                    }
                }
            
            }
        
        }
    }
}

/*#include<stdio.h>

void main() {
    int a[6] = {-1, 0, 1, 2, -1, -4}, n = 6;
    int i, j, k, sum;

    for (i = 0; i < n - 2; i++) {
        for (j = i + 1; j < n - 1; j++) {
            for (k = j + 1; k < n; k++) {
                if (a[i] + a[j] + a[k] == 0) {
                    printf("[%d, %d, %d]\n", a[i], a[j], a[k]);
                }
            }
        }
    }
}*/