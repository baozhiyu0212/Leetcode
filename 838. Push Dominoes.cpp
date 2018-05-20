class Solution {
public:
    string pushDominoes(string dominoes) {
        string prev = dominoes;
        string next = onestep(dominoes);
        while(prev!=next){
            prev = next;
            next = onestep(next);
        }
        return next;
    }
    
    string onestep(string dominoes){
        for(int i=0;i<dominoes.size();i++){
            if(dominoes[i]=='.'){
                if(i==0 && dominoes[1]=='L') dominoes[i]='L';
                else if(i==dominoes.size()-1 && dominoes[dominoes.size()-2]=='R') dominoes[i]='R';
                else{
                    if(dominoes[i-1]=='R' && dominoes[i+1]!='L') dominoes[i] = 'A';
                    if(dominoes[i-1]!='R' && dominoes[i+1]=='L') dominoes[i] = 'B';
                }
            }
        }
        for(int i=0;i<dominoes.size();i++){
            if(dominoes[i]=='A') dominoes[i]='R';
            if(dominoes[i]=='B') dominoes[i]='L';
        }
        return dominoes;
    }
};
