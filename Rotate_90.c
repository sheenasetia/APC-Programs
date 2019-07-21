#include <stdio.h>
#include <stdlib.h>
void Rotate_90(int m, int n,int a[m][n])
{
    int temp;
    for(int i=0;i<m/2;i++)
    {
        for(int j=i;j<n-1-i;j++)
        {
            temp=a[i][j];
            a[i][j]=a[m-1-j][i];
            a[m-1-j][i]=a[n-1-i][m-1-j];
            a[n-1-i][m-1-j]=a[j][n-1-i];
            a[j][n-1-i]=temp;
        }
    }
}
int main()
{
    int m,n;
    scanf("%d %d",&m,&n);
    int arr[m][n];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    Rotate_90(m,n,arr);
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d  ",arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}
