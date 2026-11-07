class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size(), m = tasks.size();

        using P2 = pair<int, int>;
        using P3 = tuple<long long, int, int>;

        priority_queue<P2, vector<P2>, greater<>> freeS;
        priority_queue<P3, vector<P3>, greater<>> busy;

        for (int i = 0; i < n; i++) freeS.push({servers[i], i});

        vector<int> ans(m);
        long long t = 0;

        for (int j = 0; j < m; j++) {
            t = max(t, (long long)j);

            // release servers that are done by time t
            while (!busy.empty() && get<0>(busy.top()) <= t) {
                auto [ft, w, idx] = busy.top();
                busy.pop();
                freeS.push({w, idx});
            }

            // nobody free: wait for the earliest server
            if (freeS.empty()) {
                t = get<0>(busy.top());
                while (!busy.empty() && get<0>(busy.top()) <= t) {
                    auto [ft, w, idx] = busy.top();
                    busy.pop();
                    freeS.push({w, idx});
                }
            }

            auto [w, idx] = freeS.top();
            freeS.pop();
            ans[j] = idx;
            busy.push({t + tasks[j], w, idx});
        }
        return ans;
    }
};