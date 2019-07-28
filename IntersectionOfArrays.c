#include <stdio.h>
#include <stdlib.h>
//intersection of sorted arrays
//Complexity : O(n1+n2)
int* intersect(int* A, int n1,int* B, int n2, int *len1) { //returns array outputing intersection
    int *arr=(int*)malloc(1*sizeof(int));
    int k=1,i=0,j=0;
    while(i<n1 && j<n2)
    {
        if(A[i]<B[j])
        {
            i++;
        }
        else if(A[i]>B[j])
        {
            j++;
        }
        else
        {
            arr=(int*)realloc(arr,k*sizeof(int));
            arr[k-1]=A[i];
            k++;
            i++;
            j++;
        }
    }
    *len1=k-1;
    return arr;
}

int main()
{
    int N1;
    printf("enter size of 1st array:\n");
    scanf("%d",&N1);
    int arr1[N1];
    printf("enter elements:\n");
    for(int i=0;i<N1;i++)
    {
        scanf("%d",&arr1[i]);
    }
    int N2;
    printf("enter size of 2nd array:\n");
    scanf("%d",&N2);
    int arr2[N2];
    printf("enter elements:\n");
    for(int i=0;i<N2;i++)
    {
        scanf("%d",&arr2[i]);
    }
    int x=0;
    int *len1=&x;
    int *res=intersect(arr1,N1,arr2,N2,len1);
    printf("Intersection : ");
    for(int i=0;i<x;i++)
    {
        printf("%d , ",res[i]);
    }
    return 0;
}
