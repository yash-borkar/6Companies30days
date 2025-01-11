// https://leetcode.com/problems/top-k-frequent-words/

class comp{
    public:
        bool operator()(pair<string, int> &a, pair<string, int> &b) {
            if (a.second == b.second) return a.first < b.first; 
            return a.second > b.second;  
        }
};

class Solution {
public:

    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int>mp;
        for(auto s:words) mp[s]++;

        vector<pair<string, int>> v(mp.begin(), mp.end());
        sort(v.begin(), v.end(), comp());

        vector<string> ans;

        for(int i=0; i<k; i++){
            ans.push_back(v[i].first);
        }

        return ans;

    }
};