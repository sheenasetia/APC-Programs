#include <stdio.h>
#include <stdlib.h>
//find three integers such that the sum is closest to a given target
//Complexity Constraint : O(n^2)
 int Comparator(const void* a,const void* b)
{
    return (*((int*)a)- *((int*)b));
}

int threeSumClosest(int* A, int n1, int B) {

  int i=0,j=1,k=n1-1,sum=0,x,su=A[0]+A[1]+A[2];
  qsort(A,n1,sizeof(int),Comparator);
 while(i<n1)
  {
      j=i+1;
      k=n1-1;
      while(j<k)
      {
        sum=A[i]+A[j]+A[k];
        if(abs(B-sum)<abs(B-su))
        {
            su=sum;
        }
        if(sum<B)
            {
                j++;
            }
        else
            {
                k--;
            }
      }
      i++;

  }
  return su;
}
int main()
{
   int N1;
    printf("enter size of array:\n");
    scanf("%d",&N1);
    int arr1[N1];
    printf("enter elements:\n");
    for(int i=0;i<N1;i++)
    {
        scanf("%d",&arr1[i]);
    }
    printf("enter the target");
    int target;
    scanf("%d",&target);
    printf("closest sum to %d is : %d ",target,threeSumClosest(arr1,N1,target));
    return 0;
}
