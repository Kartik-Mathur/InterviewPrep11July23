class Solution {
public:
	bool isPallindrome(string &x, int i, int j) {

		while (i < j) {
			if (x[i++] != x[j--]) return false;
		}
		return true;
	}

	int solve(string &s, int i, vector<int> &dp) {
		// base case
		if (i >= s.size() - 1) return 0;
		if (isPallindrome(s, i, s.size() - 1)) return 0;
		if (dp[i] != -1) return dp[i];
		// recursive case
		int ans = INT_MAX;

		for (int j = i; j < s.size(); ++j)
		{
			if (isPallindrome(s, i, j)) {
				int choti_cuts = solve(s, j + 1, dp);
				if (choti_cuts != INT_MAX) ans = min(ans, 1 + choti_cuts);
			}
		}
		return dp[i] = ans;
	}

	int minCut(string &s) {
		vector<int> dp(s.size() + 1, -1);
		return solve(s, 0, dp);
	}
};


// class Solution {
// public:
// 	bool isPallindrome(string &x, int i, int j) {

// 		while (i < j) {
// 			if (x[i++] != x[j--]) return false;
// 		}
// 		return true;
// 	}

// 	int solve(string &s, int start, int end, vector<int> &dp) {
// 		// base case
// 		if (start >= end) return 0;
// 		if (isPallindrome(s, start, end)) return 0;
// 		if (dp[start] != -1) return dp[start];
// 		// recursive case
// 		int ans = INT_MAX;

// 		for (int j = start; j < s.size(); ++j)
// 		{
// 			if (isPallindrome(s, start, j)) {
// 				int choti_cuts = solve(s, j + 1, end, dp);
// 				if (choti_cuts != INT_MAX) ans = min(ans, 1 + choti_cuts);
// 			}
// 		}
// 		return dp[start] = ans;
// 	}

// 	int minCut(string &s) {
// 		vector<int> dp(s.size() + 1, -1);
// 		return solve(s, 0, s.size() - 1, dp);
// 	}
// };