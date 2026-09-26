class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string_view, string_view> mp;
        mp.reserve(knowledge.size());
        for (auto& kv : knowledge) {
            mp.emplace(string_view(kv[0]), string_view(kv[1]));
        }

        string result;
        result.reserve(s.size());

        int n = s.size();
        int i = 0;
        while (i < n) {
            char c = s[i];
            if (c == '(') {
                int j = i + 1;
                while (s[j] != ')') j++;

                string_view key(s.data() + i + 1, j - i - 1);
                auto it = mp.find(key);
                result += (it != mp.end()) ? it->second : string_view("?");

                i = j + 1;
            } else {
                result += c;
                i++;
            }
        }

        return result;
    }
};