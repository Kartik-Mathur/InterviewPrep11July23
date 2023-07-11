class Solution {
public:
	int solve(string &s, string &x, int i, int j,
	          vector< vector<int> > &dp) {
		// base case
		if (i == s.size()) return x.size() - j;
		if (j == x.size()) return s.size() - i;
		if (dp[i][j] != -1) return dp[i][j];
		// recursive case
		if (s[i] != x[j]) {
			int op1 = solve(s, x, i, j + 1, dp);
			int op2 = solve(s, x, i + 1, j + 1, dp);
			int op3 = solve(s, x, i + 1, j, dp);

			return dp[i][j] = 1 + min(op1, min(op2, op3));
		}
		else return dp[i][j] = solve(s, x, i + 1, j + 1, dp);
	}


	int minDistance(string &s, string &x) {

		vector< vector<int> > dp(s.size() + 1, vector<int>(x.size() + 1, -1));
		return solve(s, x, 0, 0, dp);

	}
};