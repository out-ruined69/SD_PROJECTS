#include <iostream>
using namespace std;



int partitie(int a[], int st, int dr)
{
    int pivot = a[st], nr = 0;
    for (int i=st+1;i<=dr;i++)
        if (a[i]>= pivot)
            nr++;
    //cauta un pivot mai bun, mai catre mijloc
    int indpivot;
    indpivot=st+nr;
    int aux;
    aux=a[st];
    a[st]=a[indpivot];
    a[indpivot]=aux;

    int i=st,j =dr;

    while (i<indpivot && j>indpivot)
    {

        while (a[i] >= pivot)
            i++;

        while (a[j] < pivot)
            j--;

        if (i < indpivot && j > indpivot)
            {
                int aux;
                aux=a[i];
                a[i]=a[j];
                a[j]=aux;
                i++;
                j--;
            }

    }

    return indpivot;
}


//algortitmul pt quicksort
void quickSort(int a[], int st, int dr)
{
    if (st<dr)
    {
        int pivot=partitie(a,st,dr);

        //sorteaza separat sub-arrayurile
        quickSort(a, st, pivot - 1);//st
        quickSort(a, pivot + 1, dr);//dr
    }
}



int main()
{
    int a[] = {23,543,2234,54,234,23,434,546,345,6547,54,69,420};
    int n = sizeof(a)/sizeof(a[0]);
    quickSort(a, 0, n-1);
      for(int i=0;i<n;i++)
        cout<<a[i]<<" ";


    return 0;
}
