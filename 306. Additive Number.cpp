class Solution {
    vector<vector<string>> res;
public:
    bool isAdditiveNumber(string s) {
        dfs(s,vector<string>(),0);
        if(res.size()==0) return false;
        return true;
    }
private:    
    void dfs(string s, vector<string> temp, int index){
        if(temp.size()>=3 && !valid(temp)) return;
        else if(temp.size()>=3 && index>=s.size()){ 
            res.push_back(temp);
            return;
        }
        
        for(int i=index;i<s.size();i++){
            string cur = s.substr(index,i-index+1);
            if((cur[0]=='0' && cur.size()>1)) break;
            temp.push_back(cur);
            dfs(s,temp,i+1);
            temp.pop_back();
        }
        
        
        
    }
    
    bool valid(vector<string> temp){
        if(temp.size()<3) return false;
        for(int i=2;i<temp.size();i++){
            if(temp[i]!=add(temp[i-1],temp[i-2])) return false;
        }
        return true;
    }
    
    string add(string n, string m){
            string res;
            int i=n.size()-1, j=m.size()-1, carry=0;
            while(i>=0 || j>=0){
                int sum=carry+(i>=0 ? (n[i--]-'0') : 0) + (j>=0?  (m[j--]-'0') : 0);
                res.push_back(sum%10+'0');
                carry=sum/10;
            }
            if(carry) res.push_back(carry+'0');
            reverse(res.begin(), res.end());
            return res;
        }
};
