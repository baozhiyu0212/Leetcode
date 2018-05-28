class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string,vector<string>> m;
        for(int i=0;i<paths.size();i++){
            istringstream ss(paths[i]);
            string p,cur;
            ss>>p;
            p += '/';
            while(ss>>cur){
                auto iter = cur.find_first_of('(');
                string p2 = cur.substr(0,iter);
                string content = cur.substr(iter+1);
                content.pop_back();
                m[content].push_back(p+p2);
            }
        }
        vector<vector<string>> res;
        for(auto iter= m.begin();iter!=m.end();iter++){
            if(iter->second.size()>1)
                res.push_back(iter->second);
        }
        return res;
    }
};
