
class Solution {
public:
    void visit(TreeNode* root,vector<TreeNode*>& ans){
        if(root==NULL) return;
        ans.push_back(root);
        visit(root->left,ans);
        visit(root->right,ans);
    }
    vector<TreeNode*> preorderTraversal(TreeNode* root) {
        vector<TreeNode*> ans;
        visit(root,ans);
        return ans;
    }
    void flatten(TreeNode* root) {
        vector<TreeNode*> ans = preorderTraversal(root);
        int n = ans.size();
        for(int i=0 ; i<n-1 ;i++){
            ans[i]->right = ans[i+1];
            ans[i]->left = NULL;
        }
    }
};