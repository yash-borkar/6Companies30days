// https://leetcode.com/problems/count-number-of-nice-subarrays/

class Solution {
public:
    int numberOfSubarraysHelper(vector<int>& nums, int k){
        int l = 0;
        int r = 0;
        int count = 0;
        int sum = 0;

        while(r < nums.size()){
            if(k < 0) return 0;
            sum += nums[r];

            while(sum > k){
                sum -= nums[l];
                l++;
            }

            count += r - l + 1;
            r++;      
        }
        return count;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        for(int i=0; i<nums.size(); i++){
            if(nums[i] % 2 == 0) nums[i] = 0;
            else nums[i] = 1;
        }

        return numberOfSubarraysHelper(nums, k) - numberOfSubarraysHelper(nums, k-1);
    }
};
