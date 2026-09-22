class Solution {
public:
    int n, k;
    struct Node {
        int prod;
        int cnt[5][5];
    };
    vector<Node> tree;

    Node makeLeaf(int v) {
        Node node{};
        node.prod = v % k;
        for (int s = 0; s < k; s++) {
            for (int t = 0; t < k; t++) node.cnt[s][t] = 0;
            int t = (s * node.prod) % k;
            node.cnt[s][t] = 1;
        }
        return node;
    }

    Node merge(const Node& L, const Node& R) {
        Node node{};
        node.prod = (L.prod * R.prod) % k;
        for (int s = 0; s < k; s++) {
            int mid = (s * L.prod) % k;
            for (int t = 0; t < k; t++) {
                node.cnt[s][t] = L.cnt[s][t] + R.cnt[mid][t];
            }
        }
        return node;
    }

    void build(int node, int l, int r, vector<int>& nums) {
        if (l == r) { tree[node] = makeLeaf(nums[l]); return; }
        int mid = (l + r) / 2;
        build(2*node, l, mid, nums);
        build(2*node+1, mid+1, r, nums);
        tree[node] = merge(tree[2*node], tree[2*node+1]);
    }

    void update(int node, int l, int r, int idx, int val) {
        if (l == r) { tree[node] = makeLeaf(val); return; }
        int mid = (l + r) / 2;
        if (idx <= mid) update(2*node, l, mid, idx, val);
        else update(2*node+1, mid+1, r, idx, val);
        tree[node] = merge(tree[2*node], tree[2*node+1]);
    }

    Node query(int node, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) return tree[node];
        int mid = (l + r) / 2;
        if (qr <= mid) return query(2*node, l, mid, ql, qr);
        if (ql > mid) return query(2*node+1, mid+1, r, ql, qr);
        Node leftRes = query(2*node, l, mid, ql, qr);
        Node rightRes = query(2*node+1, mid+1, r, ql, qr);
        return merge(leftRes, rightRes);
    }

    vector<int> resultArray(vector<int>& nums, int k_, vector<vector<int>>& queries) {
        n = nums.size();
        k = k_;
        tree.assign(4 * n, Node());
        build(1, 0, n - 1, nums);

        int startResidue = 1 % k;   // <-- the fix: reduce 1 mod k

        vector<int> result;
        result.reserve(queries.size());
        for (auto& q : queries) {
            int index = q[0], value = q[1], start = q[2], x = q[3];
            update(1, 0, n - 1, index, value);
            Node res = query(1, 0, n - 1, start, n - 1);
            result.push_back(res.cnt[startResidue][x]);
        }
        return result;
    }
};