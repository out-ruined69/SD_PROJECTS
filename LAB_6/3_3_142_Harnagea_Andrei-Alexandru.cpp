class Solution {
public:

vector<string> findRepeatedDnaSequences(string s) {
    map <string, int> secv;
    vector <string> rep;

    for(int i=0;i+10<=s.size();i++){
        string aux;
        aux=s.substr(i,10);
        secv[aux]++;
        auto it = secv.find(aux);

    }

     for(auto it:secv){
        if(it.second>1)
            rep.push_back(it.first);
    }

    return rep;
}
};
