class Solution {
public:
    // Morris traversal

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr = root;
        TreeNode* pred;
        while(curr!=NULL){
            if(curr->left != NULL){ // find predecessor
                pred = curr->left;
                while(pred->right!=NULL && pred->right!=curr){
                    pred = pred->right;
                }
                if(pred->right == NULL){// link pred to curr and move cuur to the left
                    pred->right = curr;
                    curr = curr->left;
                }
                if(pred->right == curr){// unlink
                    pred->right = NULL;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }
            else{
                ans.push_back(curr->val);
                curr = curr->right;
            }
        }
        return ans;
    }
};