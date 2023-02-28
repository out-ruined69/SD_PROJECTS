#include<iostream>
using namespace std;
struct Node
{
int Data;
Node *Next;
};
int main()
{
    int nr1,nr2;
    int n=0,l=1;
    Node *pred =NULL;
    Node *head1 = NULL;
    Node *head2 = NULL;
    Node *p = NULL;
    Node *p1 = NULL;
    Node *p2 = NULL;


    cin>>nr1;

    while(nr1!=0)
    {
        int c;
        c=nr1%10;
        nr1=nr1/10;
        p=new Node();
        p->Data=c;
        p->Next=NULL;
        if(head1 == NULL)
        {
            head1 = p;
            pred=head1;
        }
        else
        {
            pred->Next = p;
            pred=p;
        }
    }


cin>>nr2;

    while(nr2!=0)
    {
        int c;
        c=nr2%10;
        nr2=nr2/10;
        p=new Node();
        p->Data=c;
        p->Next=NULL;
        if(head2 == NULL)
        {
            head2 = p;
            pred=head2;
        }
        else
        {
            pred->Next = p;
            pred=p;
        }
    }
    p2=head2;
    p1=head1;
    int carry;
    carry=0;
            while(p1!=NULL && p2!=NULL)
            {
                if(p1->Data+p2->Data+carry<10)
                {
                //cout<<p1->Data+p2->Data+carry<<" ";
                n=n+l*(p1->Data+p2->Data+carry);
                l=l*10;
                carry = 0;
                }
                else
                {

                //cout<<(p1->Data+p2->Data+carry)%10<<" ";
                n=n+l*((p1->Data+p2->Data+carry)%10);
                l=l*10;
                 carry=1;
                }


                p1 = p1->Next;
                p2 = p2->Next;

            }

    while(p1!=NULL)
    {
        if(carry!=0)
            {//cout<<p1->Data+carry<<" ";
            n=n+l*(p1->Data+carry);
            l=l*10;
            carry=0;
            }
        else
            {//cout<<p1->Data<<" ";
            n=n+(l*p1->Data);
            l=l*10;
            }
            p1 = p1->Next;
    }

 while(p2!=NULL)
    {
        if(carry!=0)
            {//cout<<p2->Data+carry<<" ";
            n=n+l*(p2->Data+carry);
            l=l*10;
            carry=0;
            }
        else
            {//cout<<p2->Data<<" ";
            n=n+(l*p2->Data);
            l=l*10;
            }
            p2 = p2->Next;
    }

    if (carry!=0)
        {//cout<<carry<<" ";
        n=n+l*1;}
        cout<<endl<<n;
return 0;
}
