#include <stdio.h>
#include <stdlib.h>
struct Interval
{
    int start;
    int end;
};
int* max(int *a,int *b)
{
    return *a>*b?*a:*b;
}
struct Interval* Merge(struct Interval *arr,int n,struct Interval *res,int *res_size)
{
    int cnt=1;
    res=(struct Interval*)realloc(res,cnt*sizeof(struct Interval));
    res[0]=arr[0];
    for(int i=0;i<n;i++)
    {
        if(arr[i].start <= res[cnt-1].end)
        {
            res[cnt-1].end=max(&res[cnt-1].end,&arr[i].end);
        }
        else
        {
            cnt++;
            res=(struct Interval*)realloc(res,cnt*sizeof(struct Interval));
            res[cnt-1]=arr[i];
        }
    }
    *res_size=cnt;
    return res;
}
int main()
{
    int n;
    scanf("%d",&n);
    struct Interval *arr=(struct Interval *)malloc(sizeof(struct Interval)*n);
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&arr[i].start,&arr[i].end);
    }
    struct Interval *res=(struct Interval *)malloc(sizeof(struct Interval)*n);
    int size=n;
    res=Merge(arr,n,res,&size);
    for(int i=0;i<size;i++)
    {
        printf("%d %d\n",res[i].start,res[i].end);
    }
    return 0;
}
