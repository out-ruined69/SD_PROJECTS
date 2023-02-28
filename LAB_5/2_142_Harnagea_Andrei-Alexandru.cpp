#include <iostream>
using namespace std;

struct Tree {
    int Data;
    Tree *Left;
    Tree *Right;
};
Tree *Root = NULL;

Tree* Insert(int x, Tree *Root)
{
    Tree *p1, *p;
    int d=1;
    p1=NULL;
    p = Root;
    d=1;
    while ( p!= NULL && d!=0 )
        if(p->Data > x)
        {
            p1 = p;
            p = p->Left;
            d=-1;
        }
    else
        if(x>p->Data)
        {
            p1=p;
            p=p->Right;
            d=1;
        }
        else
            d=0;

        if(p == NULL)
        {
            p = new Tree;
            p->Data = x;
            p -> Left = NULL;
            p -> Right = NULL;

            if(p1==NULL)
                Root = p;
            else
                if(d<0)
                    p1->Left = p;
                else
                    p1->Right = p;
        }
    return Root;
}

Tree* Eliminate(Tree * Root, int val)
{
    Tree* ascd=NULL;
    Tree* p = Root;
    //Cauta nodul cu valoarea val si-l pune in p
    while(p!=NULL && p->Data!=val)
    {
        ascd=p;
        if(p->Data > val)
            p=p->Left;
        else
            p=p->Right;
    }

    if(p==NULL)
    {
        cout<<"Nu exista valoarea "<<val<<endl;
        return Root;
    }
    else
        //cout<<"Exista!"<<endl;
    {
        //Caz 1 : Nodul este frunza
        if(p->Left == NULL && p->Right== NULL)
        {
            if(p!=Root)
            {
                if(ascd->Left == p)
                    ascd->Left = NULL;
                else
                    ascd->Right = NULL;
            //ii taie conexia catre p
            }

        }
        else
            //Caz 2 : are doi copii
            if(p->Left!=NULL && p->Right!=NULL)
            {
                Tree * succ = NULL;

                succ = p->Right;
                while(succ->Left!=NULL)
                    succ = succ->Left;

                int aux = succ->Data;

                Root = Eliminate(Root, succ->Data); //celalalt copil

                p->Data = aux;

            }
            else //Caz 3 : are un copil
            {
                Tree * q;
                if(p->Left!=NULL)
                    q=p->Left;
                else
                    q=p->Right;

                if(p!=Root)
                {
                    if(p == ascd->Left)
                        ascd->Left = q;
                    else
                        ascd->Right = q;
                }

                else
                    Root = q;

            }
    }
    return Root;
}



void SRD(Tree * Root)
{
    if(Root == NULL)
        return;
    SRD(Root->Left);

    cout<<Root->Data<<" ";

    SRD(Root->Right);

}


int main() {

    Root= Insert(2,Root);
    Root= Insert(23,Root);
    Root= Insert(69,Root);
    Root= Insert(8,Root);
    Root= Insert(12,Root);
    Root= Insert(10,Root);
    Root= Insert(19,Root);
    Root= Insert(6,Root);
    Root= Insert(1,Root);
    Root= Insert(14,Root);

    SRD(Root);
    cout<<endl;
    Root = Eliminate(Root, 19); //Are un singur copil
    SRD(Root);
    Root = Eliminate(Root, 1); // Nu are niciun copil
    cout<<endl;
    SRD(Root);
    cout<<endl;
    Root = Eliminate(Root, 8); //Are 2 copii
    SRD(Root);
    cout<<endl;



    return 0;
}
