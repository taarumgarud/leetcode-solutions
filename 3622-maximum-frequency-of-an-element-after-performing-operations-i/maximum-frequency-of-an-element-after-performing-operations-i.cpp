class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        unordered_map<int, int> cnt;
        map<int, int> line;

        for (int x : nums) {
            cnt[x]++;
            line[x - k]++;
            line[x + k + 1]--;
            line[x] += 0;  
        }

        int ans = 1;
        int active = 0;

        for (auto &[x, delta] : line) {
            active += delta;
            ans = max(ans, min(active, cnt[x] + numOperations));
        }

        return ans;
    }
};