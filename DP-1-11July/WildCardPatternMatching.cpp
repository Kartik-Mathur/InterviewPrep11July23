class Solution {
public:

	bool solve(string &s, string &p, int i, int j, vector< vector<int> > &dp) {
		// base case
		if (i == s.size()) {
			for (int k = j ; k < p.size() ; k++) {
				if (p[k] != '*') return dp[i][j] = false;
			}
			return dp[i][j] = true;
		}

		if (dp[i][j] != -1) {
			return dp[i][j] == 1 ? true : false;
		}

		if (j == p.size()) return dp[i][j] = false;

		// recursive case
		if (s[i] == p[j] || p[j] == '?') {
			return dp[i][j] = solve(s, p, i + 1, j + 1, dp);
		}
		else if (p[j] == '*') {
			return dp[i][j] = solve(s, p, i + 1, j, dp) || solve(s, p, i, j + 1, dp);
		}
		return dp[i][j] = false;
	}

	bool isMatch(string &s, string &p) {
		vector< vector<int> > dp(s.size() + 1, vector<int>(p.size() + 1, -1));
		return solve(s, p, 0, 0, dp);
	}
};













