//mergesort

#include <iostream>
using namespace std;

void combina(int a[], int st, int mij, int dr) {
        //a1 e de la st la mij si a2 ia elementele de la mij+1 la dr
    int n1 = mij-st+1;
    int n2=dr-mij;
    int a1[n1],a2[n2];

    for(int i=0;i<n1;i++)
        a1[i]=a[st+i];
    for(int i=0;i<n2;i++)
        a2[i]=a[mij+i+1];

   int i,j,k;
   i=0;
   j=0;
   k=st;
        //ordonam elementele din a1 si a2 si le punem in poz corecte in a
   while(i<n1 && j<n2)
   {if(a1[i] <= a2[j])
    {
    a[k]=a1[i];
    i++;
   }
   else
   {
       a[k]=a2[j];
       j++;
   }
   k++;
   }
   //punem elementele ramase
   while(i<n1)
   {
       a[k]=a1[i];
       i++;
       k++;
   }

    while(j<n2)
    {
        a[k] = a2[j];
        j++;
        k++;
  }
}


void mergesort(int a[], int st,int dr)
{
   if (st < dr) {

    int mij = st + (dr - st) / 2; //dupa m impartim vectorul in doua

    mergesort(a, st, mij);
    mergesort(a, mij + 1, dr);

    combina(a, st, mij, dr);
  }
}




int main() {
  int a[] = {6, 5, 12, 10, 9, 1,34,324,43,543,24,5,7,686,679,74,3};
  int n = sizeof(a) / sizeof(a[0]);

  mergesort(a, 0, n - 1);

 for (int i = 0; i < n; i++)
    cout << a[i] << " ";
  return 0;
}
