class LogSystem {
    map<string,int> m;
    map<string,int> helper;
public:
    LogSystem() {
        helper["Year"] = 4;
        helper["Month"] = 7;
        helper["Day"] = 10;
        helper["Hour"] = 13;
        helper["Minute"] = 16;
        helper["Second"] = 19;
    }
    
    void put(int id, string timestamp) {
        m[timestamp] = id;
    }
    
    vector<int> retrieve(string s, string e, string gra) {
        vector<int> res;
        int len = helper[gra];
        s = s.substr(0,len);
        e = e.substr(0,len);
        for(auto iter=m.begin();iter!=m.end();iter++){
            string temp = iter->first.substr(0,len);
            if(s<=temp && temp<=e) res.push_back(iter->second);
            else if(temp>e) break;
        }
        return res;
        
    }

};

/**
 * Your LogSystem object will be instantiated and called as such:
 * LogSystem obj = new LogSystem();
 * obj.put(id,timestamp);
 * vector<int> param_2 = obj.retrieve(s,e,gra);
 */
