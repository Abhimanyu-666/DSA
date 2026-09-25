class Solution {
public:
    string expr;
    int idx = 0;

    // Parses a single letter OR a {...} group, returns its set of words
    set<string> parseFactor() {
        if (expr[idx] == '{') {
            idx++; // consume '{'
            set<string> result = parseExpr();
            idx++; // consume '}'
            return result;
        } else {
            // single lowercase letter
            string s(1, expr[idx]);
            idx++;
            return {s};
        }
    }

    // Parses concatenation of factors (cartesian product), 
    // stops at ',' or '}' or end of string
    set<string> parseTerm() {
        set<string> result = {""}; // start with empty string as identity for concat

        while (idx < (int)expr.size() && expr[idx] != ',' && expr[idx] != '}') {
            set<string> factorSet = parseFactor();
            set<string> newResult;
            for (const string& a : result) {
                for (const string& b : factorSet) {
                    newResult.insert(a + b);
                }
            }
            result = newResult;
        }
        return result;
    }

    // Parses comma-separated terms (union), stops at '}' or end of string
    set<string> parseExpr() {
        set<string> result;
        result = parseTerm(); // first term

        while (idx < (int)expr.size() && expr[idx] == ',') {
            idx++; // consume ','
            set<string> termSet = parseTerm();
            result.insert(termSet.begin(), termSet.end());
        }
        return result;
    }

    vector<string> braceExpansionII(string expression) {
        expr = expression;
        idx = 0;
        set<string> resultSet = parseExpr();
        return vector<string>(resultSet.begin(), resultSet.end());
    }
};