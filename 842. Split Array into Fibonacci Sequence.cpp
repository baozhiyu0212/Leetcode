class Solution {
    vector<vector<int>> res;
public:
    vector<int> splitIntoFibonacci(string s) {
        dfs(s,vector<int>(),0);
        if(res.size()==0) return {};
        return res[0];
    }
    
    void dfs(string s, vector<int> temp, int index){
        if(temp.size()>=3 && !valid(temp)) return;
        else if(temp.size()>=3 && index>=s.size()){ 
            res.push_back(temp);
            return;
        }
        
        for(int i=index;i<s.size();i++){
            string cur = s.substr(index,i-index+1);
            if((cur[0]=='0' && cur.size()>1) || stol(cur)>INT_MAX) break;
            temp.push_back(stol(cur));
            dfs(s,temp,i+1);
            temp.pop_back();
        } 
    }
    
    bool valid(vector<int> temp){
        if(temp.size()<3) return false;
        for(int i=2;i<temp.size();i++){
            if(temp[i]!=temp[i-1]+temp[i-2]) return false;
        }
        return true;
    }
};
