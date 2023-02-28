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

void Interval(Tree * Root, int k1, int k2)
{
    if(Root==NULL)
        return;
    else
    {
        if(Root->Data <= k2 && Root->Data >=k1 )
        {
            cout<<Root->Data<<" ";
            Interval(Root->Left,k1,k2);
            Interval(Root->Right,k1,k2);
        }
        else
            if(Root->Data<k1)
                Interval(Root->Right, k1,k2);
            else
                Interval(Root->Left, k1,k2);
    }
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
    Interval(Root, 3,40);

    return 0;
}
