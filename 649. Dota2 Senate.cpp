class Solution {
public:
    string predictPartyVictory(string senate) {
        int r = 0, d = 0, rnum = 0, dnum = 0;
        queue<char> q;
        for(int i=0;i<senate.size();i++){
            q.push(senate[i]);
            if(senate[i]=='R') rnum++;
            else dnum++;
        }
        while(rnum>0 && dnum>0){
            char c = q.front();
            if(c=='R'){
                if(d>0) {
                    q.pop();
                    d--;
                    rnum--;
                }
                else{
                    r++;
                    q.pop();
                    q.push(c);
                }
            }
            else{
                if(r>0) {
                    q.pop();
                    r--;
                    dnum--;
                }
                else{
                    d++;
                    q.pop();
                    q.push(c);
                }
            }
        }
        if(q.back()=='R') return "Radiant";
        return "Dire";
    }
};
