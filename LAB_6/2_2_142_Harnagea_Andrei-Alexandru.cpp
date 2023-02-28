#include <iostream>
using namespace std;

struct Hash{
    char lit;
    bool valab;
    int val;
};

int main() {

    Hash*h;
    h = new Hash[12];

    for(int i=0;i<11;i++){
        h[i].valab=1;
        h[i].lit='#';
        h[i].val=0;
    }

    char lit[] ={ 'a','b','c','d','e','f','g','h'};
    int frc[]={24,60,35,70,13,49,59,68};

    for(int i=0;i<=7;i++){
        int ind;
        ind=frc[i]%11;

        if(h[ind].valab==1){
            h[ind].valab=0;
            h[ind].val=frc[i];
            h[ind].lit=lit[i];
        }
        else{
            ind=0;
            while(h[ind].valab==0)
                ind++;

        h[ind].valab=0;
        h[ind].val=frc[i];
        h[ind].lit=lit[i];
    }}

    for(int i=0;i<=7;i++)
        //if(h[i].lit!='#')
            cout<<h[i].lit<<" "<<h[i].val<<endl;

    return 0;
}
