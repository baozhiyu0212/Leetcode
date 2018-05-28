class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> v;
        vector<string> res;
        dfs(v,"0000000000",num,0);
        for(int i=0;i<v.size();i++){
            if(trans(v[i])!="")
                res.push_back(trans(v[i]));
        }
        return res;
    }
private: 
    void dfs(vector<string>& v, string temp, int num, int index){
        if(num==0) {
            v.push_back(temp); return;
        }
        if(index>=temp.size()) return;
        
        for(int i=index;i<temp.size();i++){
            temp[i] = '1';
            dfs(v,temp,num-1,i+1);
            temp[i] = '0';
        }
        return;
    }
    
    const string trans(const string& s){
        int hour = 0, minute = 0;
        int base_hour = 1, base_min = 1;
        string h = s.substr(0,4);
        string m = s.substr(4);
        for(int i=3;i>=0;i--){
            if(h[i]=='1') hour += base_hour;
            base_hour*=2;
        }
        for(int i=5;i>=0;i--){
            if(m[i]=='1') minute += base_min;
            base_min *= 2;
        }
        if(hour>11 || minute>59) return "";
        h = to_string(hour);
        if(minute>=10) m = to_string(minute);
        else m = "0" + to_string(minute);
        return h + ':' + m;
    }
};
