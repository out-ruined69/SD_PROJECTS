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

void SRD(Tree * Root)
{
    if(Root == NULL)
        return;
    SRD(Root->Left);

    cout<<Root->Data<<" ";

    SRD(Root->Right);

}

void RSD(Tree * Root)
{
    if(Root == NULL)
        return;
    cout<<Root->Data<<" ";
    RSD(Root->Left);
    RSD(Root->Right);
}

void SDR(Tree * Root)
{
    if(Root == NULL)
        return;
    SDR(Root->Left);
    SDR(Root->Right);
    cout<<Root->Data<<" ";
}

Tree * findLCA ( Tree * Root, int n1, int n2)
{
    if(Root == NULL)
        return NULL;

    if(Root->Data < n1 && Root->Data < n2)
        return findLCA(Root->Right,n1,n2);
    if(Root->Data > n1 && Root->Data > n2)
        return findLCA(Root->Left,n1,n2);


    return Root;
}

void afisLCA(Tree * Root,int n1, int n2)
{
    Tree * p = Root;

    p= findLCA(p,n1,n2);
    cout<<p->Data<<endl;
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

    SRD(Root);
    cout<<endl;

    afisLCA(Root, 12,6);

    return 0;
}
