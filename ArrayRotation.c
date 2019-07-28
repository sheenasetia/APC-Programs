//Rotating an array x times 
//Approach :( x % size of array )rotations
#include <stdio.h>
#include <stdlib.h>

void ArrayRotation(int *arr,int n,int r)
{
    r=r%n;
    for(int i=0;i<r;i++)
    {
        int temp=arr[n-1];
        for(int j=n-1;j>0;j--)
        {
            arr[j]=arr[j-1];
        }
        arr[0]=temp;
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
    int r;
    scanf("%d",&r);
    ArrayRotation(arr,n,r);
    for(int i=0;i<n;i++)
    {
        printf("%d",arr[i]);
    }
    return 0;
}
