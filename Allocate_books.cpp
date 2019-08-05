#include <iostream>
#include<vector>
using namespace std;
/* -----Binary Search---- */
/* allocate books to 'm' no. of students
 * max no. of pages alloted to a studnt should be minimum
 * each student must be alloted at least 1 book
 * allotment must be contiguous
*/
int Students(vector<int> &arr,int mid)
{
    int i=0,N=arr.size(),sum=0,c=1;
        while(i<N)
        {
            if(sum+arr[i]>mid)
            {
                c++;
                sum=arr[i];
            }
            else
            {
                sum+=arr[i];
            }
            i++;
        }
        return c;
}
int books(vector<int> &A, int B) {
    int max_sum=0,N=A.size(),max_n=0;
    for(int i=0;i<N;i++)
    {
        max_sum=max_sum+A[i];
        if(A[i]>max_n)
        {
            max_n=A[i];
        }
    }
     int l=max_n,r=max_sum,mid,sum=0,c=0;
    while(l<r)
    {
        mid=(l+r)/2;
        c=Students(A,mid);
        /*if(c==B)
        return l;*/
        if(c<=B)
            r=mid;
        else
        l=mid+1;

    }
    return l;
}

int main()
{
    int N;
    cout<<"enter no. of books";
    cin>>N;
    cout<<"enter series of pages in books";
    vector<int> a;
    int x;
    for(int i=0;i<N;i++)
    {
        cin>>x;
        a.push_back(x);
    }
    int B;
    cout<<"enter no. of students ";
    cin>>B;
    cout<<"minimum of maximum no. of pages alloted"<<books(a,B);
    return 0;
}
