class Solution {
public:

	// int solve(int n, int k, vector< vector<int> > &dp) {
	// 	// base case
	// 	if (k == 1 || n <= 1) return dp[n][k] = n;
	// 	if (dp[n][k] != -1) return dp[n][k];
	// 	// recursive case
	// 	int ans = INT_MAX;
	// 	for (int f = 1; f <= n ; f++) {
	// 		ans = min(ans, max(solve(f - 1, k - 1, dp), solve(n - f, k, dp)) + 1);
	// 	}
	// 	return dp[n][k] = ans;
	// }

	int solve(int n, int k, vector< vector<int> > &dp) {
		// base case
		if (k == 1 || n <= 1) return dp[n][k] = n;
		if (dp[n][k] != -1) return dp[n][k];
		// recursive case
		int ans = INT_MAX;
		int s = 1;
		int e = n;

		while (s <= e) {

			int mid = (s + e) / 2;
			int op1 = solve(mid - 1, k - 1, dp);
			int op2 = solve(n - mid, k, dp);

			ans = min(ans, max(op1, op2) + 1);
			if (op2 > op1) s = mid + 1;
			else e = mid - 1;
		}

		return dp[n][k] = ans;
	}

	int superEggDrop(int k, int n) {

		vector< vector<int> > dp(n + 1, vector<int>(k + 1, -1));

		return solve(n, k, dp);
	}
};