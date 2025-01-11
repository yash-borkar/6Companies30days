// https://leetcode.com/problems/russian-doll-envelopes/

class Solution {
public:
    bool check(vector<vector<int>>& envelopes, int curr, int prev){
        if(envelopes[curr][0] > envelopes[prev][0] && envelopes[curr][1] > envelopes[prev][1]){
                return true;
        }
        return false;
    }

    int solveUsingMemoisation(vector<vector<int>>& envelopes, int prev, int curr, vector<vector<int> >& dp) {
       //base case
       if(curr >= envelopes.size() ) {
           return 0;
       } 
       //if ans already exists
       if(dp[curr][prev+1] != -1 ) {
           return dp[curr][prev+1];
       }

       int include = 0;
       if(prev == -1 || check(envelopes, curr, prev)) {
            include = 1 + solveUsingMemoisation(envelopes, curr, curr+1, dp);
       }
       int exclude  = 0 + solveUsingMemoisation(envelopes, prev, curr+1, dp);
       dp[curr][prev+1] = max(include, exclude);
       return dp[curr][prev+1];
    }

    int solveUsingBS(vector<vector<int>>& envelopes) {

        sort(envelopes.begin(), envelopes.end(), [](vector<int>& a, vector<int>& b) {
            if(a[0] == b[0])
                return a[1] > b[1]; // If widths are the same, sort by height in descending order
            return a[0] < b[0];
        });

        vector<int> heights;
        for(auto& envelope : envelopes) {
            heights.push_back(envelope[1]);
        }

        vector<int> ans;
        //initial state
        ans.push_back(heights[0]);

        for(int i=1; i<heights.size(); i++) {
            if(heights[i] > ans.back()) {
                ans.push_back(heights[i]);
            }
            else {
                //just bada number exist krta hai
                int index = lower_bound(ans.begin(), ans.end(), heights[i]) - ans.begin();
                //replace 
                ans[index] = heights[i];
            }
        }
        return ans.size();
    }


    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // sort(envelopes.begin(), envelopes.end());

        // int n = envelopes.size();
        // int prev = -1;
        // int curr = 0;
        // vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        // int ans = solveUsingMemoisation(envelopes, prev, curr, dp);
        // return ans;

        int ans = solveUsingBS(envelopes);
        return ans;
    }
};