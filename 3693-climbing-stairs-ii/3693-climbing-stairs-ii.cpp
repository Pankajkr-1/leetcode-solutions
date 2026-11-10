class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<long long> dp(n + 1, LLONG_MAX);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int k = 1; k <= 3 && i - k >= 0; k++) {
                dp[i] = min(dp[i], dp[i - k] + costs[i - 1] + k * k);
            }
        }
        return (int)dp[n];
    }
};