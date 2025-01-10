// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

class Solution {
public:
    int maxProfitHelper(int i, int canBuy, int cap, vector<int>& prices, int n,
                    vector<vector<vector<int>>> &dp) {

        if(cap == 0) return 0;
        if(i >= n) return 0;

        if(dp[i][canBuy][cap] != -1) return dp[i][canBuy][cap];

        if(canBuy == 1){
            int buy = -prices[i] + maxProfitHelper(i+1, 0, cap, prices, n, dp);
            int noBuy = 0 + maxProfitHelper(i+1, 1, cap, prices, n, dp);
            return dp[i][canBuy][cap] = max(buy, noBuy);
        }
        else{
            int sell = prices[i] + maxProfitHelper(i+1, 1, cap-1, prices, n, dp);
            int noSell = 0 + maxProfitHelper(i+1, 0, cap, prices, n, dp);
            return dp[i][canBuy][cap] = max(sell, noSell);
        }

        return dp[i][canBuy][cap];
    }

    int maxProfit(int k, vector<int>& prices) {
        // 1 --> u can buy
        // 0 --> u can't buy
        int n = prices.size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int>(k+1, -1)));
        return maxProfitHelper(0, 1, k, prices, n, dp);
    }
};