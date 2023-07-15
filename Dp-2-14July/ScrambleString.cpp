class Solution {
public:

	bool isPermutation(string s1, string s2) {
		int freq[26] = {0};
		for (int i = 0 ; i < s1.size(); i++) {
			freq[s1[i] - 'a']++;
		}

		for (int i = 0 ; i < s2.size(); i++) {
			freq[s2[i] - 'a']--;
		}

		for (int i = 0; i < 26; ++i)
		{
			if (freq[i] != 0) return false;
		}
		return true;
	}

	bool solve(string s1, string s2, int len, map< pair<string, string>, bool> &dp) {
		// base case
		if (!isPermutation(s1, s2)) return dp[ {s1, s2} ] = false;

		if (len == 1) return dp[ {s1, s2} ] = true;

		if (dp.find({s1, s2}) != dp.end()) return dp[ {s1, s2}];

		// recursive case
		for (int i = 1; i < len ; i++) {
			string x = s1.substr(0, i);
			string y = s1.substr(i, len - i);

			string xd = s2.substr(0, i);
			string yd = s2.substr(i, len - i);

			if (solve(x, xd, i, dp) and solve(y, yd, len - i, dp)) return dp[ {s1, s2} ] = true;

			xd = s2.substr(0, len - i);
			yd = s2.substr(len - i, i);
			if (solve(x, yd, i, dp) and solve(xd, y, len - i, dp)) return dp[make_pair(s1, s2)] = true;
		}

		return dp[ {s1, s2} ] = false;
	}

	bool isScramble(string s1, string s2) {
		map< pair<string, string>, bool> dp;
		if (s1.size() != s2.size()) return false;

		return solve(s1, s2, s1.size(), dp);
	}
};