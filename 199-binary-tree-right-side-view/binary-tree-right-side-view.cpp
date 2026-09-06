class Solution {
public:

    int levels(TreeNode* root){
        if(root==NULL) return 0;
        else return 1 + max(levels(root->left),levels(root->right));
    }
 
    void preorder(TreeNode* root, vector<int>& ans ,int level){
        if(root==NULL) return;
        ans[level] = root->val;
        preorder(root->left, ans , level+1);
        preorder(root->right, ans , level+1);

    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans(levels(root),0);
        preorder(root,ans,0);
        return ans;
    }
};