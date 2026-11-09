class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        int m = arrival.size();

        set<int> freeS;
        for (int i = 0; i < k; i++) freeS.insert(i);

        // (finishTime, serverId)
        priority_queue<pair<long long, int>,
                       vector<pair<long long, int>>,
                       greater<>> busy;

        vector<int> cnt(k, 0);

        for (int i = 0; i < m; i++) {
            // release servers that are done by arrival[i]
            while (!busy.empty() && busy.top().first <= arrival[i]) {
                freeS.insert(busy.top().second);
                busy.pop();
            }

            if (freeS.empty()) continue;   // dropped

            auto it = freeS.lower_bound(i % k);
            if (it == freeS.end()) it = freeS.begin();   // wrap around

            int id = *it;
            freeS.erase(it);
            cnt[id]++;
            busy.push({(long long)arrival[i] + load[i], id});
        }

        int mx = *max_element(cnt.begin(), cnt.end());
        vector<int> ans;
        for (int i = 0; i < k; i++)
            if (cnt[i] == mx) ans.push_back(i);
        return ans;
    }
};