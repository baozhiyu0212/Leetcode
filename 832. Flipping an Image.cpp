class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        if(A.size()<1) return A;
        for(int i=0;i<A.size();i++){
            reverse(A[i].begin(),A[i].end());
        }
        for(int i =0;i<A.size();i++){
            for(int j=0;j<A[0].size();j++){
                if(A[i][j]==1) A[i][j]=0;
                else if(A[i][j]==0) A[i][j] =1;
            }
        }
        return A;
    }
};
