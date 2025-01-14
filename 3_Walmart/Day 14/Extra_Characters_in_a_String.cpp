// https://leetcode.com/problems/extra-characters-in-a-string/

class Solution {
public:
    int solve(string& s, unordered_map<string, int>&mp, int idx, vector<int> &dp) {
        if (idx >= s.size()) return 0;
        if(dp[idx] != -1) return dp[idx];

        string currStr = "";
        int ans = s.size();
        for (int currIdx = idx; currIdx < s.size(); currIdx++){
            currStr.push_back(s[currIdx]);
            int currAns = ((mp.count(currStr))? 0 : currStr.size())
                            + solve(s, mp, currIdx + 1, dp);
            
            ans = min(ans, currAns);
        }
        return dp[idx] = ans;
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        vector<int> dp(s.size(), -1);
        unordered_map<string, int>mp;
        for (string& word : dictionary) mp[word]++;
        
        int ans = solve(s, mp, 0, dp);
        return ans;
        
    }
};