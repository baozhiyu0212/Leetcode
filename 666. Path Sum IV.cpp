class Solution {
public:
    int pathSum(vector<int>& nums) {
        vector<vector<int>> v(5,vector<int>(9,-1));
        for(auto i:nums){
            int row,col,val;
            val = i%10;
            i/=10;
            col = i%10;
            i/=10;
            row = i;
            v[row][col] = val;
        }
        int res = 0;
        int row = v.size(), col = v[0].size();
        for(int i=1;i<row;i++){
            for(int j=1;j<col;j++){
                if(v[i][j]==-1) continue;
                if(i==row-1 || (v[i+1][j*2]==-1 && v[i+1][j*2-1]==-1)){
                    int h = i, pos = j;
                    while(h>=1){
                        res += v[h][pos];
                        h--;
                        pos = pos%2==0?pos/2:pos/2+1;
                    }
                }
            }
        }
        return res;
    }
};
