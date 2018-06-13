/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<string>> printTree(TreeNode* root) {
        int h = getheight(root);
        int width = pow(2,h)-1;
        vector<vector<string>> res(h,vector<string>(width,""));
        dfs(res,root,0,0,width-1);
        return res;
    }
    
    void dfs(vector<vector<string>>& res, TreeNode* root,int lvl, int left, int right){
        if(root==NULL) return;
        if(left>right) return;
        int mid = (right-left)/2+ left;
        res[lvl][mid] += to_string(root->val);
        dfs(res,root->left,lvl+1,left,mid-1);
        dfs(res,root->right,lvl+1,mid+1,right);
    }
    
    int getheight(TreeNode* root){
        if(root==NULL) return 0;
        return 1+max(getheight(root->left),getheight(root->right));
    }
};
