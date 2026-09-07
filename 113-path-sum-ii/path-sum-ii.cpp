class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;

    void dfs(TreeNode* root, int remaining) {
        if (root == nullptr)
            return;

        // Choose
        path.push_back(root->val);
        remaining -= root->val;

        // Check: must be a leaf
        if (root->left == nullptr &&
            root->right == nullptr &&
            remaining == 0) {

            ans.push_back(path);
        }

        // Explore
        dfs(root->left, remaining);
        dfs(root->right, remaining);

        // Backtrack
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root, targetSum);
        return ans;
    }
};