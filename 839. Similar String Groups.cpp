class Solution {
public:
    int numSimilarGroups(vector<string>& A) {
        unordered_set<string> s(A.begin(),A.end());
        unordered_set<string> visited;
        int res=0;
        
        for(int i=0;i<A.size();i++){
            string cur_str = A[i];
            if(!visited.count(cur_str)) res++;
            else continue;
            
            queue<string> q;
            q.push(cur_str);
            visited.insert(cur_str);
            while(!q.empty()){
                string cur = q.front();
                q.pop();
                for(int j=0;j<A.size();j++){
                    if(!visited.count(A[j]) && valid(cur,A[j])){
                        q.push(A[j]);
                        visited.insert(A[j]);
                    } 
                }
            }
        }
        return res;
    }
    
    bool valid(string s1, string s2){
        int count = 0;
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i]) count++;
        }
        return count==2;
    }
};
