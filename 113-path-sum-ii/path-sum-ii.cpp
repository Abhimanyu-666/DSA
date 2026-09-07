class Solution {
public:
    void helper(TreeNode* root, int targetsum,vector<vector<int>> &ans , vector<int> v){
        if(root==NULL) return ;
        if(root->left== NULL && root->right==NULL){
            if(root->val == targetsum) {
                v.push_back(root->val);
                ans.push_back(v);
            }
            return ;
        } 
        v.push_back(root->val);   
        helper(root->left,targetsum-root->val,ans,v);
        helper(root->right,targetsum-root->val,ans,v);


    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> v;
        helper(root , targetSum , ans,v);
        return ans;
    }
};