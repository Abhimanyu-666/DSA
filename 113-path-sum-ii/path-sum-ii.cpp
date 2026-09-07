class Solution {
public:
    

    void helper(TreeNode* root, int remaining,vector<vector<int>>& ans,vector<int> path) {
        if (root == NULL)return;

        // Choose
        path.push_back(root->val);
        remaining -= root->val;

        // Check: must be a leaf
        if (root->left == NULL && root->right == NULL && remaining == 0) {
            ans.push_back(path);
        }

        // Explore
        helper(root->left, remaining , ans,path);
        helper(root->right, remaining,  ans , path);

        // Backtrack
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;
        helper(root, targetSum, ans , path);
        return ans;
    }
};