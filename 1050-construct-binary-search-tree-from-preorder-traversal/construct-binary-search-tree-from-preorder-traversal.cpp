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
    TreeNode* insert(TreeNode* root, int val) {
        if(root==NULL) return new TreeNode(val);
        if(root->val > val){// go left
            if(root->left ==NULL){
                TreeNode* temp = new TreeNode(val);
                root->left = temp;
            }
            else insert(root->left,val);
        }
        else {
            if(root->right==NULL){
                TreeNode* temp =  new TreeNode(val);
                root->right = temp;
            }
            else insert(root->right,val);
        }
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& pre) {
        int n = pre.size();
        TreeNode* root = new TreeNode(pre[0]);
        for(int i=1 ; i<n ; i++){
            insert(root,pre[i]);
        }
        return root;
    }
};