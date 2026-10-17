class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        auto digitSum = [](int x) {
            int s = 0;
            while (x) { s += x % 10; x /= 10; }
            return s;
        };

        // {{digitSum, value}, originalIndex}
        vector<pair<pair<int,int>, int>> v;
        for (int i = 0; i < n; i++)
            v.push_back({{digitSum(nums[i]), nums[i]}, i});

        sort(v.begin(), v.end());
        // v[j].second = original index of the element that belongs at position j

        vector<bool> visited(n, false);
        int swaps = 0;

        for (int i = 0; i < n; i++) {
            if (visited[i] || v[i].second == i) continue;

            int len = 0, j = i;
            while (!visited[j]) {
                visited[j] = true;
                j = v[j].second;
                len++;
            }
            swaps += len - 1;
        }
        return swaps;
    }
};