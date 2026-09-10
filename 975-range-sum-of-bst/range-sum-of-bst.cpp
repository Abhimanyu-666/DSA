class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (root == NULL) return 0;

        if (root->val < low) 
            return rangeSumBST(root->right, low, high);   // left subtree entirely too small
        if (root->val > high) 
            return rangeSumBST(root->left, low, high);    // right subtree entirely too large

        return root->val 
             + rangeSumBST(root->left, low, high) 
             + rangeSumBST(root->right, low, high);
    }
};