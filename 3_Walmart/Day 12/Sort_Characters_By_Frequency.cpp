// https://leetcode.com/problems/sort-characters-by-frequency/

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;

        for(auto i:s) mp[i]++;

        vector<pair<char, int>> freq(mp.begin(), mp.end());

        sort(freq.begin(), freq.end(), [](const pair<char, int>& a, const pair<char, int>& b) {
            return a.second > b.second;
        });

        string ans;
        for(auto i:freq) ans.append(i.second, i.first);
        return ans;

    }
};