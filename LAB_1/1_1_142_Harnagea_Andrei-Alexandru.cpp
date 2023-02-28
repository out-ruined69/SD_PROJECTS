#include<iostream>
using namespace std;

int main()
{int a[]={12,7,6,8,4,5,10},aux,i,j,n=7;

//Bubble Sort
for (i=0;i<n;i++)
    for (j=i+1;j<n;j++)
        { if (a[j]<a[i])
            {aux=a[i];
            a[i]=a[j];
            a[j]=aux;
            }
        }

for (i=0;i<n;i++)
cout<<a[i]<<" ";

return 0;
}
