#include <iostream>
using namespace std;

struct Tree {
    int Data;
    Tree *Left;
    Tree *Right;
};


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

void SRD(Tree * Root) //in-ordine
{
    if(Root == NULL)
        return;
    SRD(Root->Left);

    cout<<Root->Data<<" ";

    SRD(Root->Right);

}

void RSD(Tree * Root) //pre-ordine
{
    if(Root == NULL)
        return;
    cout<<Root->Data<<" ";
    RSD(Root->Left);
    RSD(Root->Right);
}

void SDR(Tree * Root) //post-ordine
{
    if(Root == NULL)
        return;
    SDR(Root->Left);
    SDR(Root->Right);
    cout<<Root->Data<<" ";
}

int main() {
    Tree *Root = NULL;

    Root= Insert(2,Root);
    Root= Insert(23,Root);
    Root= Insert(69,Root);
    Root= Insert(8,Root);
    Root= Insert(12,Root);
    Root= Insert(10,Root);
    Root= Insert(19,Root);
    Root= Insert(6,Root);
    Root= Insert(1,Root);

    SRD(Root);
    cout<<endl;
    RSD(Root);
    cout<<endl;
    SDR(Root);


    return 0;
}
