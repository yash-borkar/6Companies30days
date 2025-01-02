// https://leetcode.com/problems/repeated-dna-sequences/

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        int n = s.size();
        if (n < 10) return ans;

        unordered_map<string, int> mp;
        string temp = s.substr(0, 10);

        mp[temp]++;

        for (int i = 10; i < n; i++) {
            temp = temp.substr(1) + s[i];
            mp[temp]++;
        }

        for (auto &entry : mp) {
            if (entry.second > 1) {
                ans.push_back(entry.first);
            }
        }

        return ans;
    }
};