class Solution {
public:
    string s;
    int i = 0;

    vector<string> parseExpr() {
        vector<string> res = parseTerm();
        while (i < (int)s.size() && s[i] == ',') {
            i++; // consume ','
            vector<string> term = parseTerm();
            res.insert(res.end(), 
                       make_move_iterator(term.begin()), 
                       make_move_iterator(term.end()));
        }
        return res;
    }

    vector<string> parseTerm() {
        vector<string> res = {""}; // identity element for concatenation

        while (i < (int)s.size() && s[i] != ',' && s[i] != '}') {
            vector<string> factor = parseFactor();

            // fast path: skip cartesian product entirely if res is just {""}
            if (res.size() == 1 && res[0].empty()) {
                res = move(factor);
                continue;
            }

            vector<string> merged;
            merged.reserve(res.size() * factor.size());
            for (const string& a : res)
                for (const string& b : factor)
                    merged.push_back(a + b);
            res = move(merged);
        }
        return res;
    }

    vector<string> parseFactor() {
        if (s[i] == '{') {
            i++; // consume '{'
            vector<string> res = parseExpr();
            i++; // consume '}'
            return res;
        }
        // greedily consume a run of consecutive letters as ONE literal factor
        int start = i;
        while (i < (int)s.size() && islower(s[i])) i++;
        return { s.substr(start, i - start) };
    }

    vector<string> braceExpansionII(string expression) {
        s = move(expression);
        i = 0;
        vector<string> result = parseExpr();
        sort(result.begin(), result.end());
        result.erase(unique(result.begin(), result.end()), result.end());
        return result;
    }
};