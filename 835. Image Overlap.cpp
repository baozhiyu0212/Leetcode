class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int shift = A.size()-1;
        int size = A.size();
        int res = 0;
        for(int m=-shift;m<=shift;m++){
            for(int n=-shift;n<=shift;n++){
                int count = 0;
                for(int i=0;i<size;i++){
                    for(int j=0;j<size;j++){
                        if(i+m>=0 && i+m<size && j+n>=0 && j+n<size && A[i+m][j+n]==1 && 1==B[i][j]) count++;
                    }
                }
                res = max(res,count);
            }
        }
        return res;
    }
};
