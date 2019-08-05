#include <iostream>
#include<vector>
#include<climits>
/* -----Binary Search---- */
//find Combined Median of 2 sorted arrays without merging them
using namespace std;

double findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
const vector<int> &AA=A.size()<=B.size()?A:B;
const vector<int> &BB=A.size()>B.size()?A:B;
int x=AA.size();
int y=BB.size();
int l=0;
int r=x;
int diff=(x+y+1)/2;
while(l<=r)
{
    int mid1=(l+r)/2;
    int mid2=diff-mid1;
    int minLeftA=mid1==0?INT_MIN:AA[mid1-1];
    int maxRightA=mid1==x?INT_MAX:AA[mid1];
    int minLeftB=mid2==0?INT_MIN:BB[mid2-1];
    int maxRightB=mid2==y?INT_MAX:BB[mid2];
    if(minLeftA<=maxRightB && minLeftB<=maxRightA)
    {
        if((x+y)&1)
        {
            return max(minLeftA,minLeftB);
        }
        else
        {
            return (max(minLeftA,minLeftB)+min(maxRightA,maxRightB))/2.0;
        }
    }
    else
    {
        if(minLeftA>maxRightB)
        r=mid1-1;
        else if(maxRightA<minLeftB)
        l=mid1+1;
    }
}

}
int main()
{
    int M,N;
    cout<<"enter size of array1:\n";
    cin>>M;
    vector<int> arr1;
    int x;
    cout<<"enter elements:\n";
    for(int i=0;i<M;i++)
    {
        cin>>x;
        arr1.push_back(x);
    }
    cout<<"enter size of array2:\n";
    cin>>N;
    vector<int> arr2;
    cout<<"enter elements:\n";
    for(int i=0;i<N;i++)
    {
        cin>>x;
        arr2.push_back(x);
    }
    cout<<findMedianSortedArrays(arr1,arr2);
    return 0;
}
