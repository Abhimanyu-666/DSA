class Solution {
public:
    TreeNode* build(vector<int>& pre, int prestart, int preend,
                     vector<int>& post, int poststart, int postend,
                     unordered_map<int,int>& idx){
        if(prestart > preend) return NULL;
        TreeNode* root = new TreeNode(pre[prestart]);
        if(prestart == preend) return root;

        int postidx = idx[pre[prestart+1]]; // O(1) lookup
        int len = postidx - poststart + 1;

        root->left  = build(pre, prestart+1, prestart+len, post, poststart, postidx, idx);
        root->right = build(pre, prestart+len+1, preend, post, postidx+1, postend-1, idx);

        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        int n = pre.size();
        unordered_map<int,int> idx;
        for (int k = 0; k < n; k++) idx[post[k]] = k; // value -> index in POST array
        return build(pre, 0, n-1, post, 0, n-1, idx);
    }
};