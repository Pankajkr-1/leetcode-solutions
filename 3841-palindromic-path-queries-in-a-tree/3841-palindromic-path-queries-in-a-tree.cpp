class Solution {
public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        int LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        vector<vector<int>> up(LOG, vector<int>(n, 0));
        vector<int> tin(n), tout(n), depth(n);
        vector<int> pref(n, 0);
        int timer = 0;

        // Iterative DFS: enter and exit events.
        vector<tuple<int, int, bool>> st;
        st.push_back({0, 0, false});

        while (!st.empty()) {
            auto [u, p, exit] = st.back();
            st.pop_back();

            if (exit) {
                tout[u] = timer;
                continue;
            }

            tin[u] = ++timer;
            up[0][u] = p;

            for (int j = 1; j < LOG; j++) {
                up[j][u] = up[j - 1][up[j - 1][u]];
            }

            pref[u] = (u == 0 ? 0 : pref[p])
                      ^ (1 << (s[u] - 'a'));

            st.push_back({u, p, true});

            for (int v : adj[u]) {
                if (v == p) continue;
                depth[v] = depth[u] + 1;
                st.push_back({v, u, false});
            }
        }

        // Fenwick tree with XOR range updates and point queries.
        vector<int> bit(n + 2, 0);

        auto add = [&](int i, int val) {
            for (; i <= n; i += i & -i)
                bit[i] ^= val;
        };

        auto rangeUpdate = [&](int l, int r, int val) {
            add(l, val);
            add(r + 1, val);
        };

        auto pointQuery = [&](int i) {
            int ans = 0;
            for (; i > 0; i -= i & -i)
                ans ^= bit[i];
            return ans;
        };

        auto lca = [&](int u, int v) {
            if (depth[u] < depth[v])
                swap(u, v);

            int diff = depth[u] - depth[v];

            for (int j = 0; j < LOG; j++) {
                if (diff & (1 << j))
                    u = up[j][u];
            }

            if (u == v) return u;

            for (int j = LOG - 1; j >= 0; j--) {
                if (up[j][u] != up[j][v]) {
                    u = up[j][u];
                    v = up[j][v];
                }
            }

            return up[0][u];
        };

        vector<bool> ans;

        for (string& q : queries) {
            string op;
            int u;
            char c;

            stringstream ss(q);
            ss >> op >> u;

            if (op == "update") {
                ss >> c;

                int delta = (1 << (s[u] - 'a'))
                          ^ (1 << (c - 'a'));

                if (delta != 0) {
                    rangeUpdate(tin[u], tout[u], delta);
                    s[u] = c;
                }
            } else {
                int v;
                ss >> v;

                int w = lca(u, v);

                int mask = (pref[u] ^ pointQuery(tin[u]))
                         ^ (pref[v] ^ pointQuery(tin[v]))
                         ^ (1 << (s[w] - 'a'));

                // At most one character may have odd frequency.
                ans.push_back((mask & (mask - 1)) == 0);
            }
        }

        return ans;
    }
};