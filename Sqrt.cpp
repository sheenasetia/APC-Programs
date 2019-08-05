#include <iostream>
/* -----Binary Search---- */
//find sqrt of a num using binary search
using namespace std;
int findSqrt(int num)
{
    int l=0,r=num/2;
    while(l<r)
    {
        int mid=(l+r)/2;
        if((mid*mid)>num)
            r=mid-1;
        else if((mid*mid)<num)
            l=mid+1;
        else
            return mid;
    }
    return r; // r instead of l for returning floor of num which is not perfect square
}
int main()
{
    int num;
    cout<<"please input num for sqrt : ";
    cin>>num;
    cout<<"sqrt of "<<num<<" is "<<findSqrt(num);
    return 0;
}
