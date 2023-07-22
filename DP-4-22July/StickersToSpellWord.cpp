class Solution {
public:
	int solve(vector<string>& stickers, string &target,
	          map<pair<int, int>, int > &dp,
	          int currentMask = 0, int i = 0) {
		// base case
		if (currentMask == ((1 << target.size()) - 1))
			return dp[ {currentMask, i}] = 0;
		if (i == stickers.size()) {
			return dp[ {currentMask, i}] = ((1 << target.size()) - 1);
		}

		if (dp.find({currentMask, i}) != dp.end()) return dp[ {currentMask, i}];
		// recursive case
		// 1. ith sticker ko include krna hai
		int freq[26] = {0};
		for (int j = 0; j < stickers[i].size(); ++j) freq[stickers[i][j] - 'a']++;
		int nayaMask = 0;
		for (int i = 0; i < target.size(); ++i)
		{
			if (!((1 << i)&currentMask)) {
				if (freq[target[i] - 'a']) {
					nayaMask |= (1 << i);
					freq[target[i] - 'a']--;
				}
			}
		}
		int op1 = INT_MAX, op2 = INT_MAX;
		if (nayaMask != 0)
			op1 = 1 + solve(stickers, target, dp, currentMask | nayaMask, i);
		// 2. ith sticker ko exclude krna hai
		op2 = solve(stickers, target, dp, currentMask, i + 1);
		return dp[ {currentMask, i}] = min(op1, op2);
	}

	int minStickers(vector<string>& stickers, string &target) {
		map<pair<int, int>, int > dp;
		int ans = solve(stickers, target, dp);
		return ans == ( (1 << target.size()) - 1) ? -1 : ans;
	}
};









