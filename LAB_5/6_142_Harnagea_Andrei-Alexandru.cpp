#include <iostream>
#include <fstream>
using namespace std;
ifstream f("arbore.in");

struct Tree{
    int Data;
    Tree * Right;
    Tree * Left ;
};

int Inaltime(Tree * Root)
{
    if(Root == NULL)
        return -1;
    else
    {
        int r= Inaltime(Root->Left);
        int l= Inaltime(Root->Right);

        if(l>r)
            return l+1;
        else
            return r+1;
        }
}

Tree * Dreapta(Tree * Root){
    Tree * x = new Tree();
    Tree * aux = new Tree();

    x = Root->Left;
    aux = x->Right;

    x->Right = Root;
    Root->Left = aux;
    return x;
}

Tree * Stanga(Tree * Root){
    Tree * x = new Tree();
    Tree * aux = new Tree();

    x = Root->Right;
    aux = x->Left;

    x->Left = Root;
    Root->Right=aux;

    return x;
}

Tree * Inserare(Tree * Root, int val)
{
    Tree * p = new Tree();
    p->Data = val;

    if (Root == NULL)
    {
        Root=p;
        return Root;
    }

    if (p->Data < Root->Data)
    {
        Root->Left = Inserare(Root->Left, val);
    }
    else
        if (p->Data > Root->Data)
        {
            Root->Right = Inserare(Root->Right, val);
        }

        int bal;

        if(Root == NULL)
            bal=-1;
        else
            bal= Inaltime(Root->Left) - Inaltime(Root->Right);

        //Stanga-Stanga

        if ( bal > 1 && p->Data < Root->Left->Data )
            return Dreapta(Root);

        //Dreapta - Dreapta
        if (bal < -1 &&  p->Data > Root->Right->Data )
            return Stanga(Root);

        //Stanga - Dreapta

        if ( bal > 1 && p->Data > Root->Left->Data )
        {
            Root->Left = Stanga(Root->Left);
            return Dreapta(Root);
        }

        //Dreapta Stanga

        if(bal < -1 &&  p->Data < Root->Right->Data )
        {
            Root->Right = Dreapta(Root->Right);
            return Stanga(Root);
        }

        return Root;

}

void RSD(Tree * Root)
{
    if(Root == NULL)
        return;
    cout<<Root->Data<<" ";
    RSD(Root->Left);
    RSD(Root->Right);
}


int main() {
    Tree * Root = NULL;
/*
    Root = Inserare(Root, 7);
    Root = Inserare(Root, 11);
    Root = Inserare(Root, 20);
    Root = Inserare(Root, 8);
    Root = Inserare(Root, 2);
    Root = Inserare(Root, 9);
    Root = Inserare(Root, 5);
    Root = Inserare(Root, 30);
    Root = Inserare(Root, 1);
    Root = Inserare(Root, 3);
    Root = Inserare(Root, 31);
    Root = Inserare(Root, 19);
*/

  int nr;
  while(f>>nr)
  {
      Root = Inserare(Root, nr);
  }


    RSD(Root);
    return 0;
}
