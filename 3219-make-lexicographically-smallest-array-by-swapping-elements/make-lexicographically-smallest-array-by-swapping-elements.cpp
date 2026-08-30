class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<pair<int,int>> valIdx(n); // (value, original index)
        for (int i = 0; i < n; i++) {
            valIdx[i] = {nums[i], i};
        }
        sort(valIdx.begin(), valIdx.end());

        vector<int> result(n);
        int i = 0;

        while (i < n) {
            int j = i;
            // extend the group while consecutive sorted values are within limit
            while (j + 1 < n && valIdx[j+1].first - valIdx[j].first <= limit) {
                j++;
            }

            // group spans valIdx[i..j] — gather original indices, sort them
            vector<int> indices;
            for (int k = i; k <= j; k++) {
                indices.push_back(valIdx[k].second);
            }
            sort(indices.begin(), indices.end());

            // assign sorted values (valIdx[i..j].first) to sorted positions
            for (int k = 0; k <= j - i; k++) {
                result[indices[k]] = valIdx[i + k].first;
            }

            i = j + 1;
        }

        return result;
    }
};