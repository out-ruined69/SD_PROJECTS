#include<iostream>
using namespace std;

int main()
{
int a[]={3,5,6,7,10,54,64,78,23},x=10,n=9,k=0,i;

for (i=0;i<n;i++)
    if (a[i]==x)
        {cout<<"Elementul se afla pe pozitia "<<i+1<<endl; //return i+1;
        return 0;}

cout<<"Nu se afla elementul in vector";


return 0;
}
