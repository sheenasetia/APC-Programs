#include <iostream>
/* -----Binary Search---- */
//find no. of elements lying in given range
using namespace std;
int findLowerBound(int *arr,int N,int x)
{
    int l=0,r=N-1;
    while(l<r)
    {
        int mid=(l+r)/2;
        if(arr[mid]>=x)
            r=mid;
        else
            l=mid+1;
    }
    if(!(arr[l]>=x)) //if lower bound not present ,elem not there
        return -1;
    return l;
}
int findUpperBound(int *arr,int N,int x)
{
   int l=0,r=N-1;
    while(l<r)
    {
        int mid=(l+r)/2;
        if(arr[mid]>x)
            r=mid;
        else
            l=mid+1;
    }
    if(!(arr[l]>x)) //if upper bound not present
        return N;
    return l;
}
int main()
{
    int N;
    cout<<"enter size of array";
    cin>>N;
    int arr[N];
    for(int i=0;i<N;i++)
    {
        cin>>arr[i];
    }
    int a,b;
    cout<<"enter start of range";
    cin>>a;
    cout<<"enter end of range";
    cin>>b;
    int start=findLowerBound(arr,N,a);
    int last=findUpperBound(arr,N,b);
    if(start==-1)
        cout<<"No elements found";
    else
    cout<<"Number of elements in the range ("<<a<<","<<b<<") is : "<<last-start;
    return 0;
}
