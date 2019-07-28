#include <stdio.h>
#include <stdlib.h>
//find series of max ones when u can flip B zeros (NG's approach)
//sliding window protocol approach
int* maxone(int* A, int n1, int B, int *len1) { //returns array of indices series having max ones
int r=0,l=0,c=0,max=0,a=0,b=0,temp=B;
    while(r<n1)
    {
        if(A[r]==1)
        r++;
        else if(A[r]==0&&temp)
        {
            r++;
            temp--;
        }
        else
        {
            if((r-l)>max)
            {
                a=l;
                b=r-1;
                max=r-l;
            }
            while(A[l]!=0)
            l++;
            l++;
            if(l>r)    // satisfying 0 1 1 1 B=0
                r=l;
            if(temp<B)
                temp++;

        }
    }
    if((r-l)>=max)      //when r reaches n (for last series made)
    {
                a=l;
                b=r-1;
                max=r-l;
    }
    int *arr=(int*)malloc(max*sizeof(int));
    for(int i=0;i<max;i++)
    {
        arr[i]=a;
        a++;
    }
    *len1=max;
    return arr;
}
int main()
{
    //examples below:
    // int arr[12]={1 ,1 ,0 ,1 ,1 ,0 ,0 ,1 ,1 ,1 ,1,1},B=2;
    // int arr[4]={0,1,1,1},B=0;
    int N;
    printf("enter size of array:\n");
    scanf("%d",&N);
    int arr[N];
    printf("enter elements:\n");
    for(int i=0;i<N;i++)
    {
        scanf("%d",&arr[i]);
    }
    int B;
    printf("enter no of 0s to flip");
    scanf("%d",&B);
    int x=0;
    int *len1=&x;
    int *a=maxone(arr,N,B,len1);
    for(int i=0;i<x;i++)
    {
        printf("%d , ",a[i]);
    }
}
