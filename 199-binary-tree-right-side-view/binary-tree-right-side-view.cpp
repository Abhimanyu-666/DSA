class Solution {
public:

    int levels(TreeNode* root){
        if(root==NULL) return 0;
        else return 1 + max(levels(root->left),levels(root->right));
    }
 
    void nthlevel(TreeNode* root, int currlvl , int reqlvl ,vector<int>& ans){
        if(root == NULL) return;
        if(currlvl == reqlvl){
            ans[currlvl] = root->val;
            return;
        }
        nthlevel(root->left, currlvl+1 , reqlvl , ans);
        nthlevel(root->right, currlvl+1 , reqlvl , ans);
    }
    void levelOrder(TreeNode* root, vector<int>& ans){
        int n= ans.size();
        for(int i=0 ; i<n ; i++){
            nthlevel(root,0,i,ans);
            cout<<endl;
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans(levels(root),0);
        levelOrder(root,ans);
        return ans;
    }
};