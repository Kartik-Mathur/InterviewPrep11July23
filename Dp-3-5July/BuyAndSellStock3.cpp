class Solution {
public:
	int solve(vector<int>& prices, int i , bool purchase, int transCnt,
	          vector<vector<int> > &dp, int k) {
		if (i == prices.size() || transCnt == 2 * k) {
			return dp[i][transCnt] = 0;
		}
		if (dp[i][transCnt] != -1) return dp[i][transCnt];
		if (purchase == true) {
			// Mat becho
			int op1 = solve(prices, i + 1, true, transCnt, dp, k);
			// Bech do
			int op2 = prices[i] + solve(prices, i + 1, false, transCnt + 1, dp, k);
			return dp[i][transCnt] = max(op1, op2);
		}
		else {
			// Khareed lo
			int op1 = -prices[i] + solve(prices, i + 1, true, transCnt + 1, dp, k);
			// Skip kardo
			int op2 = solve(prices, i + 1, purchase, transCnt, dp, k);
			return dp[i][transCnt] = max(op1, op2);
		}
	}

	int maxProfit(int k, vector<int>& prices) {
		vector<vector<int> > dp(prices.size() + 1, vector<int>(2 * k + 1, -1));
		return solve(prices, 0, false, 0, dp, k);
	}
};