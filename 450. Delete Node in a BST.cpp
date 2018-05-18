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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return root;
        if(root->val>key) root->left = deleteNode(root->left,key);
        else if(root->val<key) root->right = deleteNode(root->right,key);
        else{
            if(root->left==NULL && root->right==NULL) return NULL;
            if(root->left==NULL && root->right!=NULL) return root->right;
            if(root->left!=NULL && root->right==NULL) return root->left;
            
            TreeNode* temp = root->right, *pre = temp->right;
            if(temp->left==NULL){
                root->val = temp ->val;
                root->right = temp->right;
            }
            else{
                while(temp->left){
                    pre = temp;
                    temp = temp->left;
                }
                root->val = temp->val;
                pre->left = temp->right;
            }      
        }
        return root;
    }
};
