#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
//minimize the absolute difference
// minimize(max(A[i],B[j],C[k])-min(A[i],B[j],C[k]))
//complexity : O(n1+n2+n3);
int findMin(int n1,int n2,int n3,int *x)
 {
     if((n1<=n2) && (n1<=n3))
     {
         *x=1;
         return n1;
     }
     else if((n2<n1) && (n2<=n3))
     {
         *x=2;
         return n2;
     }
     else
     {
         *x=3;
         return n3;
     }
 }
 int findMax(int n1,int n2,int n3)
 {
     if((n1>=n2) && (n1>=n3))
     return n1;
     else if((n2>n1) && (n2>=n3))
     return n2;
     else
     return n3;
 }
int solve(int* A, int n1, int* B, int n2, int* C, int n3) {
    int i=0,j=0,k=0,X=1,diff=INT_MAX,min,max;
    int *x=&X;
    while((i<n1) && (j<n2) && (k<n3))
    {
        min=findMin(A[i],B[j],C[k],x);
        max=findMax(A[i],B[j],C[k]);
        if((max-min)<diff)
        {
            diff=max-min;
        }
        //increment the index of array where min is found
        if(X==1)
        i++;
        if(X==2)
        j++;
        if(X==3)
        k++;
    }
    return diff;
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
    int N3;
    printf("enter size of 2nd array:\n");
    scanf("%d",&N3);
    int arr3[N3];
    printf("enter elements:\n");
    for(int i=0;i<N3;i++)
    {
        scanf("%d",&arr3[i]);
    }
    printf("minimum absolute diff is : %d ",solve(arr1,N1,arr2,N2,arr3,N3));
    return 0;
}
