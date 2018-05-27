class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        if(grid.size()<3 || grid[0].size()<3) return 0;
        int count = 0 ;
        for(int i=0;i<grid.size()-2;i++){
            for(int j=0;j<grid[0].size()-2;j++){
                set<int> s;
                s.insert(grid[i][j]);s.insert(grid[i+1][j]);s.insert(grid[i+2][j]);
                s.insert(grid[i][j+1]);s.insert(grid[i+1][j+1]);s.insert(grid[i+2][j+1]);
                s.insert(grid[i][j+2]);s.insert(grid[i+1][j+2]);s.insert(grid[i+2][j+2]);
                if(s.size()!=9) continue;
                int temp = 1; bool valid = true;
                for(auto iter=s.begin();iter!=s.end();iter++){
                    if(*iter!=temp) {
                        valid = false;break;
                    }
                    temp++;
                }
                if(!valid) continue;
                int target = grid[i][j]+grid[i][j+1]+grid[i][j+2];
                if(target==grid[i+1][j]+grid[i+1][j+1]+grid[i+1][j+2] && target==grid[i+2][j]+grid[i+2][j+1]+grid[i+2][j+2] && 
                  target==grid[i][j]+grid[i+1][j]+grid[i+2][j] && target==grid[i][j+1]+grid[i+1][j+1]+grid[i+2][j+1]  && 
                  target==grid[i][j+2]+grid[i+1][j+2]+grid[i+2][j+2] && target==grid[i][j]+grid[i+1][j+1]+grid[i+2][j+2] &&
                  target == grid[i+2][j]+grid[i+1][j+1]+grid[i][j+2])
                    count++;
            }
        }
        return count;
    }
};
