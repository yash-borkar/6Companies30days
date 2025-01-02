// https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        //find median
        int median  = n % 2 == 0 ? (n/2) - 1 : (n/2);

        int ans = 0;
        for(auto i: nums) ans += abs(i - nums[median]);

        return ans;

    }
};