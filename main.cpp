#include <iostream>
#include<climits>
//Max sum subarray (Approach 1(ii) : Brute Force ) -- O(n^2)
using namespace std;
int SubArray(int arr[],int n)
{
    int sum=0,ans=arr[0];
    for(int i=0;i<n;i++)
    {
        sum=arr[i];
        for(int j=i+1;j<n;j++)
        {
           sum+=arr[j];
           if(sum>ans)
           {
               ans=sum;
           }
        }
    }
    return ans;
}
int main()
{
    int arr[5]={2,3,-4,8};
    int y=SubArray(arr,5);
    cout<<y;
    return 0;
}
