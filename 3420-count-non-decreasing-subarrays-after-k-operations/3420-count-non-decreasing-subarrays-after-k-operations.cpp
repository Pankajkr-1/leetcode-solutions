class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0, cost = 0;
        int r = n - 1;
        deque<int> dq;  // front = leftmost segment head, back = rightmost

        for (int l = n - 1; l >= 0; --l) {
            // add nums[l] on the left
            while (!dq.empty() && nums[dq.front()] <= nums[l]) {
                int j = dq.front();
                dq.pop_front();
                int nxt = dq.empty() ? r + 1 : dq.front();
                cost += 1LL * (nums[l] - nums[j]) * (nxt - j);
            }
            dq.push_front(l);

            // shrink from the right until cost <= k
            while (cost > k) {
                int b = dq.back();
                cost -= nums[b] - nums[r];
                if (b == r) dq.pop_back();
                --r;
            }
            ans += r - l + 1;
        }
        return ans;
    }
};