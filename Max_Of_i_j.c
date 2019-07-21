#include <stdio.h>
#include <stdlib.h>

struct elem
{
    int val;
    int index;
};
int cmp(const void *a,const void *b)
{
    return ((((struct elem*)a)->val)-(((struct elem*)b)->val));
}
int main()
{
    int n;
    scanf("%d",&n);
   struct elem arr[n];
   for(int i=0;i<n;i++)
   {
       arr[i].index=i;
       scanf("%d",&arr[i].val);
   }
   qsort(arr,n,sizeof(arr[0]),cmp);
    for(int i=0;i<n;i++)
        printf("%d",arr[i].index);
    int min=arr[0].index;
    int max=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i].index-min>max)
        {
            max=arr[i].index-min;
        }
        min=arr[i].index<min?arr[i].index:min;
    }
    printf("\nmin index: %d max index : %d",min,max);
    return 0;
}
