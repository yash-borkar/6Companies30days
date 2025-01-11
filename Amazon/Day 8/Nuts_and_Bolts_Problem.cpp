// https://www.geeksforgeeks.org/problems/nuts-and-bolts-problem0431/1

class Solution {
  public:

    void matchPairs(int n, char nuts[], char bolts[]) {
        string order = "!#$%&*?@^";
    
        unordered_map<char, int> mp;
        for (int i = 0; i < order.size(); i++) {
           mp[order[i]] = i;
        }
    
        auto comparator = [&](char a, char b) {
            return mp[a] < mp[b];
        };
    
        sort(nuts, nuts + n, comparator);
        sort(bolts, bolts + n, comparator);
    }
};