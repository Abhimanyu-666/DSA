class Solution {
public:
    long long MaxTree(TreeNode* root){
        if(root == NULL) return LLONG_MIN;
        return max((long long)(root->val) , max(MaxTree(root->left), MaxTree(root->right)));

    }
    long long MinTree(TreeNode* root){
        if(root == NULL) return LLONG_MAX;
        return min((long long)(root->val) , min(MinTree(root->left), MinTree(root->right)));
    }
    bool isValidBST(TreeNode* root) {
        if(root == NULL) return true;
        if((long long)(root->val) <= MaxTree(root->left))  return false;
        else if((long long)(root->val) >= MinTree(root->right)) return false;
        return isValidBST(root->left) && isValidBST(root->right);
    }
};