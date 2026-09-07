class Solution {
public:
    void helper(TreeNode* root, long long targetsum,int &count){
        if(root==NULL) return ;
        if((long long)(root->val) == targetsum) count++;
        helper(root->left,targetsum - (long long)root->val , count);
        helper(root->right,targetsum - (long long)root->val , count);
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return 0;
        int count = 0;
        helper(root, targetSum, count);
        count+= (pathSum(root->left,targetSum)+pathSum(root->right,targetSum));
        return count;
    }
};