class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(logs.begin(), logs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        int m = queries.size();
        vector<pair<int, int>> qs;
        for (int i = 0; i < m; i++) qs.push_back({queries[i], i});
        sort(qs.begin(), qs.end());

        vector<int> ans(m);
        vector<int> freq(n + 1, 0);
        int distinct = 0;
        int l = 0, r = 0;           
        int L = logs.size();

        for (auto& [q, idx] : qs) {
            
            while (r < L && logs[r][1] <= q) {
                if (freq[logs[r][0]]++ == 0) distinct++;
                r++;
            }
            
            while (l < r && logs[l][1] < q - x) {
                if (--freq[logs[l][0]] == 0) distinct--;
                l++;
            }
            ans[idx] = n - distinct;
        }
        return ans;
    }
};