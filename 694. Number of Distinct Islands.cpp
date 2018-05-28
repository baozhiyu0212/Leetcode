class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        set<vector<pair<int,int>>> s;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    vector<pair<int,int>> temp;
                    dfs(temp,grid,i,j,i,j);
                    s.insert(temp);
                }
            }
        }
        return s.size();
    }
private:
    void dfs(vector<pair<int,int>>& temp, vector<vector<int>>& grid, int starti, int startj, int i, int j){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]!=1) return;
        
        grid[i][j] = 0;
        temp.push_back(make_pair(i-starti,j-startj));
        
        dfs(temp,grid,starti,startj,i+1,j);
        dfs(temp,grid,starti,startj,i,j+1);
        dfs(temp,grid,starti,startj,i-1,j);
        dfs(temp,grid,starti,startj,i,j-1);
    }
    
    
};
