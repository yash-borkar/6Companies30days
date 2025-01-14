// https://leetcode.com/problems/count-the-number-of-square-free-subsets/

class Solution {
public:
    int squareFreeSubsets(vector<int>& nums) {
        using ll = long long;
        map<ll,ll> mp;
        int MOD = 1e9 + 7;
        
        for(int num : nums) {
            bool flag = false;
            
            for(int i=2; i<=5; i++) {
                if(num % (i*i) == 0) {
                    flag = true;
                    break;
                }
            }
            
            if(flag) continue;
            
            vector<pair<ll,ll>> temp;
            
            for(auto [k, v] : mp) {
                if(__gcd(k, (ll)num) == 1) {
                    temp.push_back({k*num, v});
                }
            }
            
            for(auto [k, v] : temp) {
                mp[k] = (mp[k] + v)%MOD;
            }
            
            mp[num] = (mp[num] + 1)%MOD;
        }
        
        int result = 0;
        
        for(auto [k, v] : mp) {
            result = (result + v)%MOD;
        }
        
        return result;
    }
};