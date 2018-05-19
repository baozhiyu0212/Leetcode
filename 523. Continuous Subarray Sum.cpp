class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        bool twozero = false, zero = false;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==0 && nums[i-1]==0) twozero = true;
        }
        if(twozero) return true;
        if(k==0) return false;
        for(int i=0;i<nums.size()-1;i++){
            int sum=nums[i];
            for(int j=i+1;j<nums.size();j++){
                sum+= nums[j];
                if((sum%k)==0) return true;
            }
        }
        
        return false;
    }
};
