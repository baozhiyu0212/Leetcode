class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxSum=INT_MIN;
        findMaxPath(root,maxSum);
        return maxSum;
    }
private:
    int findMaxPath(TreeNode*root,int&maxSum){
        if(!root)return 0;
        int l=findMaxPath(root->left,maxSum);
        int r=findMaxPath(root->right,maxSum);
        if(l>0&&r>0){
            maxSum=max(maxSum,root->val+l+r);
            return root->val+max(l,r);
        }else if(l>0||r>0){
            maxSum=max(maxSum,root->val+max(l,r));
            return root->val+max(l,r);
        }else{
            maxSum=max(maxSum,root->val);
            return root->val;
        }
        
    }
};
