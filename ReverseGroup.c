//Reverse the array in a group of k
#include <stdio.h>
#include <stdlib.h>
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
void ReverseGroup(int *a,int n,int k)
{
    for(int i=0;i<n;i+=k)
    {
        if(i+k<=n)
        {
            for(int j=0;j<k/2;j++)
            {
                swap(&a[j+i],&a[i+k-1-j]);
            }
        }
        else
        {
            for(int j=0;j<(n-i)/2;j++) //for the array with last imperfect group
            {
                swap(&a[j+i],&a[n-1-j]);
            }
        }
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int k;
    scanf("%d",&k);
    ReverseGroup(arr,n,k);
    for(int i=0;i<n;i++)
        printf("%d",arr[i]);
    return 0;
}
