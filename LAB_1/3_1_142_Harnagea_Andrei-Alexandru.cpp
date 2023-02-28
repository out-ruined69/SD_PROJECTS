#include<iostream>
#include<string.h>
#include<bits/stdc++.h>
using namespace std;

struct anagrama{

char word[20];
char ord[20];

} a[100];

int main()
{
int n,i,j,l;
char aux[20];
char c;
cin>>n;
cin.get();

for(i=0;i<n;i++)
        {
            cin.get(a[i].word,20);
            cin.get();

            strcpy(aux,a[i].word);

            for(j=0;j<strlen(aux);j++)
                for(l=j+1;l<strlen(aux);l++)
            {
                if(aux[j]>aux[l])
                {
                    c=aux[j];
                    aux[j]=aux[l];
                    aux[l]=c;
                }
            }

            strcpy(a[i].ord,aux);

        }



for(i=0;i<n;i++)
    for(j=i+1;j<n;j++)
{
    if(strcmp(a[i].ord,a[j].ord)==1)//a[i].ord>a[j].ord
    {
        strcpy(aux,a[i].ord);
        strcpy(a[i].ord,a[j].ord);
        strcpy(a[j].ord,aux);

        strcpy(aux,a[i].word);
        strcpy(a[i].word,a[j].word);
        strcpy(a[j].word,aux);
    }
}

cout<<a[0].word<<" ";

for (i=1;i<n;i++)
    {if(strcmp(a[i].ord,a[i-1].ord)!=0)//a[i].word!=a[i-1]
    cout<<endl;

    cout<<a[i].word<<" ";
    }


return 0;
}
