//fct hash = nume.lenght%12

#include <iostream>
using namespace std;

struct list{
    string nume;
    list * next;
};

class Hash{
public:
    int b;
    list ** t;
public:
    Hash(int b){
        this->b=b;
        t = new list*[b];
        for(int i=0;i<b;i++){
            t[i]=NULL;
        }
    };
    void inserare(string nume){

        int id = nume.length()%12;
        list * q = new list();
        list * p = new list();
        q->nume=nume;
        if(t[id]==NULL)
        {
            t[id] = q;
        }
        else {
            p=t[id];
            while(p->next!=NULL){
                p=p->next;
            }

            p->next=q;
        }
    }

    void afisare(){
        for(int i=0;i<b;i++){
            cout<<endl;
            list * p =new list();
            p=t[i];
            cout<<i<<": ";
            while(p!=NULL){
                cout<<p->nume<<"; ";
                p=p->next;
            }

        }
    }

    bool apartine(string nume){

            int i = nume.length()%12;
            list * p = new list();
            p=t[i];
            while(p!=NULL){
                if(p->nume==nume)
                    return 1;
                p=p->next;
            }

        return 0;
    }

    void eliminare(string nume){
        list * p = new list();
        list * q = new list();
        q=NULL;
        int ind = nume.length()%12;
            p=t[ind];
            while(p!=NULL && nume!=p->nume){
                q=p;
                p=p->next;
            }

        if(p==NULL){
            cout<<"Nu exista!"<<endl;
        }
        else
        {
            if(q==NULL){
                t[ind] = p->next;
                delete p;
            }
            else{
                t[ind]->next=p->next;
                delete q;
            }
        }

    }

};

int main() {
    Hash h(13);
    string s="Yolo Squad";
    string s2="Jow mama";
    h.inserare("Yolo Squad");
    h.inserare("Jow mama");
    h.inserare("1234");
    h.inserare("Nico Idk");
    h.inserare("Steven Univ");
    h.inserare("ASDFG Squad");
    h.inserare("Idk IGGG");
    h.inserare("Ani Annom");
    h.inserare("Ai sdassd");
    h.inserare("Nume 12");
    h.inserare("Numee Trei");
    h.inserare("Numeee Patru");
    h.inserare("Numeeee cin");
    h.inserare("Nume s");
    h.inserare("12345");
    h.inserare("Haha Lol");
    h.inserare("Nuee Huo");
    h.inserare("Hannah Montana");
    h.inserare("Miley Cyrus");
h.afisare();
h.eliminare("12345");
cout<<endl<<"##########"<<endl;
h.afisare();
cout<<endl;
cout<<h.apartine("1234");


    return 0;
}
