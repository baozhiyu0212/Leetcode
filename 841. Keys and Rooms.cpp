class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_map<int,vector<int>> m;
        for(int i=0;i<rooms.size();i++){
            for(auto j:rooms[i]){
                m[i].push_back(j);
            }
        }
        queue<int> q;
        q.push(0);
        unordered_set<int> visited{0};
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(int i=0;i<m[cur].size();i++){
                if(visited.count(m[cur][i])) continue;
                else{
                    visited.insert(m[cur][i]);
                    q.push(m[cur][i]);
                }
            }
        }
        if(visited.size()!=rooms.size()) return false;
        return true;
    }
};
