class Solution {
public:
    int findBlackPixel(vector<vector<char>>& picture, int N) {
        unordered_map<int,vector<int>> row;
        unordered_map<int,vector<int>> col;
        int res = 0;
        for(int i=0;i<picture.size();i++){
            for(int j=0;j<picture[0].size();j++){
                if(picture[i][j]=='B'){
                    row[i].push_back(j);
                    col[j].push_back(i);
                }
            }
        }
        for(int j=0;j<picture[0].size();j++){
            bool isValid = true;
            if(col[j].size()==N){
                vector<int> temp = row[col[j][0]];
                if(temp.size()!=N){
                    continue;
                }
                for(auto i:col[j]){
                    if(row[i]!=temp){
                        isValid = false;
                        break;
                    }
                }
                if(isValid) res++;
            }
        }
        return res*N;
    }
};
