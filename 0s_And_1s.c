#include <stdio.h>
#include <stdlib.h>
void Zeros_Ones(int n,int arr[n][n])
{
    int r,c;
    for(int i=0;i<n;i++)
    {
        if(arr[0][i]==0)
        {
            r=0;
            break;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(arr[i][0]==0)
        {
            c=0;
            break;
        }
    }

    for(int i=1;i<n;i++)
    {
        for(int j=1;j<n;j++)
        {
            if(arr[i][j]==0)
            {
                arr[0][j]=0;
                arr[i][0]=0;
            }
        }
    }
    for(int i=1;i<n;i++)
    {
        if(arr[0][i]==0)
        {
            for(int j=1;j<n;j++)
            {
                arr[j][i]=0;
            }
        }
    }
    for(int i=1;i<n;i++)
    {
        if(arr[i][0]==0)
        {
            for(int j=1;j<n;j++)
            {
                arr[i][j]=0;
            }
        }
    }
    if(r==0)
    {
        for(int i=0;i<n;i++)
        {
            arr[0][i]=0;
        }
    }
    else if(c==0)
    {
        for(int i=0;i<n;i++)
        {
            arr[i][0]=0;
        }
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    int arr[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        scanf("%d",&arr[i][j]);
    }
    Zeros_Ones(n,arr);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d  ",arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}
