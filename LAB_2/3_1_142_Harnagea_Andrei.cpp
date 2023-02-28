#include<iostream>
using namespace std;

int main()
{

int a[100],b[100],i,j,n,m,k;
cout<<"Nr de elemente din a";cin>>n;
for(i=0;i<n;i++)
    cin>>a[i];

cout<<"Nr de elemente din b";cin>>m;
for(i=0;i<m;i++)
    cin>>b[i];

for(i=n-1;i>=0;i--)
    a[m+i]=a[i];

j=0;
k=0;
i=m;

while(i<n+m && j<m)
    if(a[i]<b[j])
    {

        a[k]=a[i];
        i++;
        k++;

    }
    else
    {

    a[k]=b[j];
    k++;
    j++;

    }

while(i<m+n)
{

a[k]=a[i];
k++;
i++;

}

while(j<m)
{

a[k]=b[j];
j++;
k++;

}

for(i=0;i<m+n;i++)
cout<<a[i]<<" ";

return 0;
}
