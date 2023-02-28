#include<iostream>
using namespace std;

int main()
{
int a[]={3,5,6,7,10,54,64,78,100},n=9,k=0,i,x=54;

int st=0;
int dr=n;



while (st<=dr)
    {
        int mij=(st+dr)/2;
        if(a[mij]==x)
            {cout<<"Elementul se afla pe pozitia "<<mij+1; //return mij+1;
            return 0;
            }
        if (a[mij] > x)
            dr=mij-1;
        if (a[mij] < x)
            st=mij+1;
    }


cout<<"Nu se afla elementul in vector";


return 0;
}
