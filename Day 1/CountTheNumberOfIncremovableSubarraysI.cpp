// https://leetcode.com/problems/count-the-number-of-incremovable-subarrays-i/

class Solution {
public:
    bool isIncSubArray(vector<int>& nums, int start, int end){
        int n = nums.size();
        int prev = 0;
        for(int i=0; i<n; i++){
            if(i>= start && i<= end) continue;
            if(nums[i] <= prev) return false;
            prev = nums[i];
        }
        return true;

    }

    int incremovableSubarrayCount(vector<int>& nums) {
        int ans = 0;
        for(int i=0; i<nums.size(); i++){
            for(int j=i; j<nums.size(); j++){
                if(isIncSubArray(nums, i, j)) ans++;
            }
        }
        return ans;
    }
};
