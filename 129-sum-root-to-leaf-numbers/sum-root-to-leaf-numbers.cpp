class Solution {
public:

    int ans = 0;

    void helper(TreeNode* root, int val){
        if(root==NULL) return ;
        if(root->left==NULL && root->right==NULL){
            //leaf node;
            ans += root->val;
            ans += val;
            return ;
        }
        val += root->val;
        helper(root->left, val*10);
        helper(root->right, val*10);
    }

    int sumNumbers(TreeNode* root) {
        helper(root,0);
        return ans;
    }
};