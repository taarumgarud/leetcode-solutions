class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int equals = 1;
        
        map<int, int> mp;
        for (auto i : nums) mp[i]++;
        for (auto i : mp) equals = max(equals, i.second);
        
        int maxi = 1;
        
        for (int i = 0; i < n; i++) {
            int targets[] = {nums[i], nums[i] - k, nums[i] + k};
            
            for (int target : targets) {
                auto it_start = lower_bound(nums.begin(), nums.end(), target - k);
                auto it_end = upper_bound(nums.begin(), nums.end(), target + k);
                int total_can_reach = distance(it_start, it_end);
                
                int already_equal = mp.count(target) ? mp[target] : 0;
                
                int operations_needed = total_can_reach - already_equal;
                int possible = already_equal + min(numOperations, operations_needed);
                
                maxi = max(maxi, possible);
            }
        }
        
        return max(equals, maxi);
    }
};