//find the maximum occured element in the given ranges
#include <stdio.h>
#include <stdlib.h>

int Max_Occ(int *l,int *r,int n)
{
    int max=l[0];
    for(int i=0;i<n;i++) //finding max
    {
        if(l[i]>max)
            max=l[i];
        if(r[i]>max)
            max=r[i];
    }
    int arr[max+1];
    for(int i=0;i<max+1;i++) 
    {
        arr[i]=0;
    }
    for(int i=0;i<n;i++) //fillig array
    {
        arr[l[i]]++;
        arr[r[i]+1]--;
    }
    int prev=0;
    int m=0;
    for(int i=0;i<max+1;i++) //finding max occured num
    {
        if(prev+arr[i]>m)
        {
            m=prev+arr[i];
        }
        prev=prev+arr[i];
    }
    return m;
}
int main()
{
    int n;
    scanf("%d",&n);
    int l[n];
    int r[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&l[i]);
    }
    for(int i=0;i<n;i++)
    {
        scanf("%d",&r[i]);
    }
    int x=Max_Occ(l,r,n);
    printf("%d",x);
    return 0;
}
