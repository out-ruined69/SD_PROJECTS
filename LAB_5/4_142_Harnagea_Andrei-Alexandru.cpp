#include <iostream>
#include <string.h>
using namespace std;
struct Tree {
    char sir[101];
    Tree *Left;
    Tree *Right;
};

Tree* Insert(Tree *Root, char*aux)
{
    Tree *p1, *p;
    int d=1;
    p1=NULL;
    p = Root;
    d=1;
    while ( p!= NULL && d!=0 )
        if( strcmp(p->sir,aux)>0 ) //p->Data > x
        {
            p1 = p;
            p = p->Left;
            d=-1;
        }
        else
        if(strcmp(p->sir,aux)<0)
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
        strcpy(p->sir,aux);//p->Data = x;
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

void Desc(Tree * Root)
{

    if(Root == NULL)
        return;
    Desc(Root->Right);

    cout<<Root->sir<<" ";

    Desc(Root->Left);

}

int main() {

    Tree * Root = NULL;

    char s[101], *p;
    cin.get(s,101);

    p=strtok(s," ");

    while(p!=NULL)
    {
        Root=Insert(Root, p);
        p=strtok(NULL, " ");
    }

   Desc(Root);

}
