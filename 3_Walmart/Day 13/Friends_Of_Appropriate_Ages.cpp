// https://leetcode.com/problems/friends-of-appropriate-ages/

class Solution {
public:
    bool request(int a, int b) {
        return !(   (b <= 0.5 * a + 7) || 
                    (b > a) || 
                    (b > 100 && a < 100)    );
    }
    
    int numFriendRequests(vector<int>& ages) {
        unordered_map<int, int> count;
        for (auto i : ages) count[i]++;
        int res = 0;
        for (auto a : count)
            for (auto b : count)
                if (request(a.first, b.first))
                    res += a.second * (b.second - (a.first == b.first ? 1 : 0));
        return res;
    }
};