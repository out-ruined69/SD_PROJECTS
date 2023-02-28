#include <iostream>
#include <string>
using namespace std;

struct Node{
    char lit;
    int frc;
    Node *Left;
    Node *Right;
};

struct Heap{
    int dim;
    int cap;
    Node ** nodes;
};

Node * newNode(char lit, int frec){
    Node * aux = new Node();
    aux->Left = NULL;
    aux->Right = NULL;
    aux->lit=lit;
    aux->frc=frec;
    return aux;
}

Heap * nou(int x){
    Heap * min = new Heap();
    min->dim=0;
    min->cap=x;
    min->nodes = new Node*[min->cap];
    return min;
}

void inter(Node** a,Node** b)

{
    Node* t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(Heap * h, int x){
    int mini=x;
    int st=2*x+1;
    int dr=2*x+2;

    if(st < h->dim && h->nodes[st]->frc < h->nodes[mini]->frc)
        mini = st;

    if(dr < h->dim && h->nodes[dr]->frc < h->nodes[mini]->frc)
        mini = dr;

    if(mini!=x){
        inter(&h->nodes[mini], &h->nodes[x]);
        minHeapify(h, mini);

    }

}
//luam valoare minima dintr-un heap
Node * nodmin(Heap*h){
    Node * aux = h->nodes[0];
    h->nodes[0]=h->nodes[h->dim-1];

    h->dim--;
    minHeapify(h,0);
    return aux;

}

void insert(Heap*h, Node*n){
    h->dim+=1;
    int i=h->dim-1;

    while(i && n->frc < h->nodes[(i-1)/2]->frc) {
        h->nodes[i]=h->nodes[(i-1)/2];
        i=(i-1)/2;
    }
    h->nodes[i]=n;
}

void afisCod(Node*root, int a[], int ind){
    if(root->Left){
        a[ind] = 0;
        afisCod(root->Left,a,ind+1);
    }

    if(root->Right){
        a[ind]=1;
        afisCod(root->Right,a,ind+1);
    }

    if(!(root->Left) && !(root->Right)){
        cout<<root->lit<<": ";
        for(int i=0;i<ind;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }

}

Node * CodHuffman(char lit[], int f[],int size){
    Node * root;
    Node *left, *right, *top;
    Heap * h = nou(size);

    //Cream un minheap care are capacitatea egala cu dimensiunea

    for(int i=0;i<size;i++){
        h->nodes[i]= newNode(lit[i], f[i]);
    }

    h->dim=size;

    int n=h->dim-1;

    for(int i=(n-1)/2;i>=0;i--){
        minHeapify(h,i);
    }

    while(h->dim!=1){
            left= nodmin(h);
            right= nodmin(h);
            //luam cele mai mici doua noduri , le adunam si le punem intr-un nod aux, cand le gasim le si rupem
            top = newNode(' ', left->frc+right->frc);
            top->Left=left;
            top->Right=right;
        //il punem in heap
        insert(h, top);
    }
//luam valoare minima dintr-un heap
    return nodmin(h);

}

void decode(string s, Node * root){

    Node * p = root;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='0')
            p=p->Left;
        else
            p=p->Right;

        if(p->Right==NULL && p->Left == NULL)
        {
            cout << p->lit;
            p=root;
        }

    }
}

void print(Node * root){
    if(root==NULL)
        return ;
    cout<<root->lit<<" ";
    print(root->Left);
    print(root->Right);
}

int main() {
    char lit[]={'a','e','i','o','u','y'};
    int f[]={1,2,3,4,5,6};
    int size=sizeof(lit) / sizeof (lit[0]);
    Node * root;

    root = CodHuffman(lit, f,size);
    int a[100], ind=0;
    afisCod(root, a,ind);

    string s="001010100101010101001010101110101011100";

    decode(s,root);


    return 0;
}
