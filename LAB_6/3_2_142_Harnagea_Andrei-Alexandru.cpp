class Solution {
public:


    string intToRoman(int num){
        map <int, char> cifre;
        cifre[1]='I';
        cifre[5]='V';
        cifre[10]='X';
        cifre[50]='L';
        cifre[100]='C';
        cifre[500]='D';
        cifre[1000]='M';

        string nr;
        int n=100;
        if(num/1000>0){
            for(int i=0;i<num/1000;i++)
                nr+=cifre[1000];
            num%=1000;
        }

        while(num>0){
            if(num/(9*n)==1){
                nr+=cifre[n];
                nr+=cifre[n*10];
            }
            else
            if(num/(5*n)>0){
                nr+=cifre[5*n];
                for(int i=0;i<(num/n)-5;i++){
                    nr+=cifre[n];
                }
            }
            else
            if(num/(4*n)==1){
                nr+=cifre[n];
                nr+=cifre[n*5];
            }
            else
            if(num/n>0){
                for(int i=0;i<num/n;i++){
                    nr+=cifre[n];
                }
            }
            num%=n;
            n/=10;

        }
        return nr;
    }


};
