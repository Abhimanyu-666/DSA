/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void helper(TreeNode* root, int targetsum,int &count){
        if(root==NULL) return ;
        if(root->left ==NULL && root->right == NULL){
            // leaf node;
            if(root->val == targetsum) {
                count++;    
            }
            return;
        }
        helper(root->left,targetsum-root->val,count);
        helper(root->right,targetsum-root->val,count);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int count = 0;
        helper(root,targetSum,count);
        if(count==0) return false;
        else return true;
    }
};