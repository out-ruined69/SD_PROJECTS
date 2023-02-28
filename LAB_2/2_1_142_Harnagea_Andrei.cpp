#include <iostream>

using namespace std;
int a[] = { 123,32,435,654,754,28,25,654,5642,12, 11, 13, 5, 6, 7 };
int n = sizeof(a) / sizeof(a[0]);
int lungh,maxi,aux,i;

void heapify(int n,int i){

    maxi=i;
    int st=2*i+1;
    int dr=2*i+2;

    if(a[st]>a[maxi] && st<n)
        maxi=st;
    if(a[dr]>a[maxi] && dr<n)
        maxi=dr;

    if(maxi!=i){
        aux=a[i];
        a[i]=a[maxi];
        a[maxi]=aux;
        heapify(n,maxi);
    }
}

void createHeap(){


for(i=n/2-1;i>=0;i--)
    heapify(n,i);

}

void decapitation(){

aux=a[i];
a[i]=a[0];
a[0]=aux;
lungh--;

}

void heapsort(){
lungh=n;
createHeap();
    for(i=n-1;i>0;i--)
    {
        decapitation();
        heapify(lungh,0);
    }

}

int main()
{
    heapsort();

    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
    return 0;
}
