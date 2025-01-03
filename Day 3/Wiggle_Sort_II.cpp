// https://leetcode.com/problems/wiggle-sort-ii/

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> v(nums.begin(), nums.end());

        sort(v.begin(),v.end());

        int i=1;
        int j = v.size()-1;
        while(i<nums.size()){
            nums[i] = v[j];
            j--;
            i += 2;
        }

        i=0;
        while(i<nums.size()){
            nums[i] = v[j];
            j--;
            i += 2;
        }
    }
};