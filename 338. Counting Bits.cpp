class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res;
        for(int i=0;i<=num;i++){
            res.push_back(helper(i));
        }
        return res;
    }
    
    int helper(int num){
        int count = 0 ;
        while(num){
            num &= num - 1;
            count++;
        }
        return count;
    }
};
