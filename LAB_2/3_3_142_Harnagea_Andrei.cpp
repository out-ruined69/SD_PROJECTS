#include<iostream>
using namespace std;


//Insertion sort normal
void insertion(int a[], int st, int dr)
  {int val,j;
    for(int i=st+1;i<dr+1;i++)
    {
    val = a[i] ;
    j = i-1 ;
        while (j>=st && a[j]>val)
        {
            a[j+1]= a[j] ;
            j--;
        }
        a[j+1]= val ;
    }

  }

//Quick sort normal
int partitie(int a[], int st, int dr)
{
  int pivot=a[dr] ;
  int i ,j;

  j=st;

  for (int i=st;i<dr;i++)
     {
      if(a[i]<pivot)
      {
        int temp=a[i];
      a[i]=a[j];
      a[j]=temp;
      j++;
      }
    }

    int temp=a[j];
    a[j]=a[dr];
    a[dr]=temp;

  return j;
  }


void quick(int a[], int st,int dr)
{
  if(st<dr)
  {
        int pivot=partitie(a, st, dr);
        quick(a,st,pivot-1);
        quick(a,pivot + 1, dr);
  }
}



void quick_insertion(int a[], int st, int dr)
{
  while(st<dr)
    {

    if(dr-st+1<=11) //daca lungimea arraiului <= 11 se face insertion sort
      {
        insertion(a, st, dr);
      break;
    }

    else

        {
          int pivot=partitie(a, st, dr) ;

      //sorteaza partea in care sunt mai putine elemente prima oara

      if (pivot-st<dr-pivot)
        {
          quick_insertion(a,st,pivot-1);
            st=pivot+1;
      }
      else
        {
        quick_insertion(a,pivot+1,dr);
        dr=pivot-1;
        }

     }

   }
}

int main()
{
int a[] = {23,543,2234,54,234,23,434,546,345,6547,54,69,420,535,324545,34254,21934,23400};
    int n = sizeof(a)/sizeof(a[0]);
quick_insertion(a,0,n-1);

  for(int i=0;i<n;i++)
    cout <<a[i]<<" ";
}
