// https://leetcode.com/problems/maximum-length-of-repeated-subarray/

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        for(int i=0; i<nums1.size(); i++){
            for(int j=0; j<nums2.size(); j++){
                int c = 0;
                if(nums1[i] == nums2[j]){
                    int p = i;
                    int q = j;
                    while(p<nums1.size() && q<nums2.size()){
                        if(nums1[p] == nums2[q]){
                            c++;
                            p++;
                            q++;
                        }
                        else break;
                    }
                    ans = max(ans, c);
                }
            }
        }
        return ans;
    }
};