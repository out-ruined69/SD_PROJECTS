#include<iostream>
using namespace std;

struct acr{

int ht;
int wt;

}a[100];

int main()

{
int n,i,g=0,j,aux;
cin>>n;

for (i=0;i<n;i++)
    {cin>>a[i].ht;
     cin>>a[i].wt;}


for (i=0;i<n;i++)
    for (j=i+1;j<n;j++)
        {
        if(a[i].ht<a[j].ht)
             {
            aux=a[i].ht;
            a[i].ht=a[j].ht;
            a[j].ht=aux;
            aux=a[i].wt;
            a[i].wt=a[j].wt;
            a[j].wt=aux;
            }
        }


i=0;
int anth=0,antw=0;


while(i<n-1)
{

    if(a[i].ht>=a[i+1].ht && a[i].wt>=a[i+1].wt)
        {

        g++;
        if(g==1)
            cout<<"("<<a[i].ht<<" "<<a[i].wt<<") ";

        cout<<"("<<a[i+1].ht<<" "<<a[1+i].wt<<") ";

        }


        i++;

}

if(g==0)
cout<<"Nu se poate";

return 0;
}

