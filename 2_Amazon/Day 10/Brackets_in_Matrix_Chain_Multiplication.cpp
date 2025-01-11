// https://www.geeksforgeeks.org/problems/brackets-in-matrix-chain-multiplication1024/1

class Solution {
  public:
    pair<int, string> matrixChainOrderHelper(int i, int j, vector<int> &arr, vector<vector<pair<int, string>>> &dp) {
        if (i == j) return {0, string(1, 'A' + i - 1)};

        if (dp[i][j].first != -1) return dp[i][j]; 

        int mini = INT_MAX;
        string optimalParenthesization;


        for (int k = i; k < j; k++) {
            auto left = matrixChainOrderHelper(i, k, arr, dp);
            auto right = matrixChainOrderHelper(k + 1, j, arr, dp);

            int cost = arr[i - 1] * arr[k] * arr[j] + left.first + right.first;
            if (cost < mini) {
                mini = cost;
                optimalParenthesization = "(" + left.second + right.second + ")";
            }
        }

        dp[i][j] = {mini, optimalParenthesization}; 
        return dp[i][j];
    }

    string matrixChainOrder(vector<int> &arr) {
        int n = arr.size();
        vector<vector<pair<int, string>>> dp(n, vector<pair<int, string>>(n, {-1, ""}));
        return matrixChainOrderHelper(1, n - 1, arr, dp).second; 
    }
};