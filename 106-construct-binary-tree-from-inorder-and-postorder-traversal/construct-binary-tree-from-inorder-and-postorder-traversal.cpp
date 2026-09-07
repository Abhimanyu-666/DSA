class Solution {
public:
    TreeNode* build(vector<int>& in, int inlo, int inhi,
                     vector<int>& post, int postlo, int posthi,
                     unordered_map<int,int>& idx){
        if(inlo > inhi) return NULL;

        TreeNode* root = new TreeNode(post[posthi]);
        if(inlo == inhi) return root;

        // O(1) lookup instead of linear scan
        int i = idx[post[posthi]];

        int leftEle = i - inlo;
        int rightEle = inhi - i;

        root->left  = build(in, inlo, i-1, post, postlo, postlo+leftEle-1, idx);
        root->right = build(in, i+1, inhi, post, postlo+leftEle, posthi-1, idx);

        return root;
    }

    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        int n = in.size();
        unordered_map<int,int> idx;
        for (int k = 0; k < n; k++) idx[in[k]] = k;   // value -> index in inorder
        return build(in, 0, n-1, post, 0, n-1, idx);
    }
};