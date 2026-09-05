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
    int levels(TreeNode* root){
        if(root==NULL) return 0;
        return 1+ max(levels(root->left),levels(root->right));
    }
    void nthlevel(TreeNode* root, int currlvl, int reqlvl, vector<int> &v){
    if(root == NULL) return;
    if(currlvl == reqlvl){ v.push_back(root->val); return; }
    nthlevel(root->left, currlvl+1, reqlvl, v);
    nthlevel(root->right, currlvl+1, reqlvl, v);
    }

    void lOrder(TreeNode* root, vector<vector<int>> &ans){
        int n = levels(root);
        for(int i=1; i<=n; i++){
            vector<int> v;
            nthlevel(root, 1, i, v);
            if(i % 2 == 0) reverse(v.begin(), v.end()); // only reverse even levels
            ans.push_back(v);
        }
    }
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        lOrder(root,ans);
        return ans;
    }
};