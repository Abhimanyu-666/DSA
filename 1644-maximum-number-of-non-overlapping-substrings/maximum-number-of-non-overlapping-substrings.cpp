class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        vector<int> first(26, -1), last(26, -1);

        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            if (first[c] == -1) first[c] = i;
            last[c] = i;
        }

        vector<pair<int,int>> candidates; // (start, end)

        for (int i = 0; i < n; i++) {
            int end = last[s[i] - 'a'];
            bool valid = true;
            int j = i;
            while (j <= end) {
                int cc = s[j] - 'a';
                if (first[cc] < i) { valid = false; break; }
                end = max(end, last[cc]);
                j++;
            }
            if (valid) candidates.push_back({i, end});
        }

        // sort by end asc, tie-break by start desc (shorter first)
        sort(candidates.begin(), candidates.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
            if (a.second != b.second) return a.second < b.second;
            return a.first > b.first;
        });

        vector<string> result;
        int curEnd = -1;
        for (auto& [start, end] : candidates) {
            if (start > curEnd) {
                result.push_back(s.substr(start, end - start + 1));
                curEnd = end;
            }
        }
        return result;
    }
};
