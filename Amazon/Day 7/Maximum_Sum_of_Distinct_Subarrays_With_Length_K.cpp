// https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        long long ans = 0;
        long long sum = 0;
        
        for (int i = 0; i < k; i++) {
            sum += nums[i];
            mp[nums[i]]++;
        }
        
        if (mp.size() == k) ans = max(ans, sum);
        
        for (int i = k; i < nums.size(); i++) {
            sum -= nums[i - k];
            mp[nums[i - k]]--;
            if (mp[nums[i - k]] == 0) {
                mp.erase(nums[i - k]);
            }
            
            sum += nums[i];
            mp[nums[i]]++;
            
            if (mp.size() == k) {
                ans = max(ans, sum);
            }
        }
        
        return ans;
    }
};