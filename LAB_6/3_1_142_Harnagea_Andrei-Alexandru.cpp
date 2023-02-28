class Solution {
public:



    void sol(string digits, int i, string aux,vector<string>&rasp) {
        map <int, vector<char>> taste;
        taste[2]={'a','b','c'};
        taste[3]={'d','e','f'};
        taste[4]={'g','h','i'};
        taste[5]={'j','k','l'};
        taste[6]={'m','n','o'};
        taste[7]={'p','q','r','s'};
        taste[8]={'t','u','v'};
        taste[9]={'w','x','y','z'};

        if(i == digits.length()){
            rasp.push_back(aux);
            return ;
        }

        vector<char> s=taste[(int)(digits[i])-48];
        for(int j=0;j<s.size();j++){
            aux+=s[j];
            sol(digits,i+1,aux,rasp);
            aux.pop_back();
        }

    }

    vector<string> letterCombinations(string digits) {
        vector<string> rasp;
        if(digits.length()==0)
            return rasp;
        string aux;
        sol(digits,0,aux,rasp);
        return rasp;
    }
};