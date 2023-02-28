#include<iostream>
using namespace std;

int main()
{int a[]={12,7,6,8,4,5,10},aux,i,l,j,n=7,m;

//Selection Sort
for(i=0;i<n-1;i++)
    {
        m=a[i];
        l=i;
        for (j=i+1;j<n;j++)
            {
                if (m>a[j])
                    {
                    m=a[j];
                    l=j;
                    }
            }
            aux=a[i];
            a[i]=a[l];
            a[l]=aux;

    }

for (i=0;i<n;i++)
cout<<a[i]<<" ";

return 0;
}
