class Solution {
public:
    unordered_map<string, vector<char>> mp;
    unordered_set<string> bad;   // memoization

    bool dfs(string curr) {
        if (curr.size() == 1) return true;
        if (bad.count(curr)) return false;

        vector<string> nextRows;
        build(curr, 0, "", nextRows);

        for (auto &next : nextRows) {
            if (dfs(next)) return true;
        }

        bad.insert(curr);   // mark as impossible
        return false;
    }

    void build(string &curr, int i, string path, vector<string> &res) {
        if (i == curr.size() - 1) {
            res.push_back(path);
            return;
        }

        string key = curr.substr(i, 2);
        if (!mp.count(key)) return;

        for (char c : mp[key]) {
            build(curr, i + 1, path + c, res);
        }
    }

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        for (auto &s : allowed)
            mp[s.substr(0,2)].push_back(s[2]);

        return dfs(bottom);
    }
};
