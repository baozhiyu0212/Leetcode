class Solution {
public:
    string findReplaceString(string s, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        unordered_map<int,string> m1;
        unordered_map<int,string> m2;
        for(int i=0;i<indexes.size();i++){
            m1[indexes[i]] = sources[i];
            m2[indexes[i]] = targets[i];
        }
        sort(indexes.rbegin(),indexes.rend());
        for(int i=0;i<indexes.size();i++){
            int index = indexes[i],len = m1[index].size();
            if(s.substr(index,len)==m1[index]){
                s.erase(index,len);
                s.insert(index,m2[index]);
            }
        }
        return s;
        
    }
};
