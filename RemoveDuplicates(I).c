#include <stdio.h>
#include <stdlib.h>
//remove duplicates from a sorted array in O(n)
int removeDuplicates(int* A, int n1) {  //returns new length of array
    int j=0,i;
    for(i=1;i<n1;i++)
    {
        if(A[i]!=A[j])
        {
            j++;
            A[j]=A[i];
        }
    }
    return j+1;
}
int main()
{
    int N;
    printf("enter size of array:\n");
    scanf("%d",&N);
    int arr[N];
    printf("enter elements:\n");
    for(int i=0;i<N;i++)
    {
        scanf("%d",&arr[i]);
    }
    N=removeDuplicates(arr,N);
    printf("array after : \n");
    for(int i=0;i<N;i++)
    {
        printf("%d",arr[i]);
    }
    return 0;
}
