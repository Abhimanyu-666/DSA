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

    TreeNode* build(vector<int>& pre,int prestart,int preend, vector<int>& post, int poststart, int postend){
        if(prestart>preend) return NULL;
        TreeNode* root = new TreeNode(pre[prestart]);
        if(prestart == preend) return root;
        int postidx = poststart;
        while(post[postidx] != pre[prestart+1]){
            postidx++;
        }
        int len = postidx-poststart+1; // length of LST
        root->left = build(pre, prestart+1 , prestart+len , post , poststart , postidx);
        root->right = build(pre, prestart+len+1, preend , post , postidx+1 , postend-1);

        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        int n = pre.size();
        return build(pre,0,n-1,post,0,n-1);
    }
};