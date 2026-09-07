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
    TreeNode* build(vector<int>& in,int inlo, int inhi, vector<int>& post, int postlo, int posthi){
        if(inlo>inhi) return NULL;
        TreeNode* root = new TreeNode(post[posthi]);
        if(inlo==inhi) return root;
        // search root in inorder array
        int i = inlo;
        while(i<=inhi){
            if(in[i]==post[posthi]) break;
            i++;
        }
        // now i is at the root node
        int leftEle = i-inlo;
        int rightEle = inhi-i;
        root->left = build(in, inlo , i-1 , post , postlo ,postlo+leftEle-1);
        root->right = build(in, i+1 , inhi , post, postlo+leftEle, posthi-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        int n = in.size();
        return build(in,0,n-1,post,0,n-1);
    }
};