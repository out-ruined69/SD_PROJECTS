#include<iostream>
using namespace std;

int main()
{int a[]={12,7,6,8,4,5,10},aux,i,l,j,n=7;

//Insertion Sort
for (i=1;i<n;i++)
{
    l = a[i];
    j=i-1;

    while(j>=0 && a[j]>l)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=l;

}

for (i=0;i<n;i++)
cout<<a[i]<<" ";

return 0;
}
