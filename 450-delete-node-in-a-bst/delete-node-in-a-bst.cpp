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

    TreeNode* iop(TreeNode* root){
        TreeNode* pred = root->left;
        while(pred->right){
            pred = pred->right;
        }
        return pred;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;
        if(root->val == key){
            // case 1 : 0 child node
            if(root->left==NULL && root->right==NULL) return NULL;

            // Case 2 : 1 child node
            else if(root->left==NULL || root->right==NULL){
                if(root->left!=NULL) return root->left;
                else return root->right;
            }

            // Case 3 : 2 child nodes
            else{
                TreeNode* pred = iop(root);
                root->val = pred->val;
                root->left = deleteNode(root->left,pred->val);
            }

        }
        root->left = deleteNode(root->left,key);
        root->right = deleteNode(root->right,key);

        return root;
    }
};