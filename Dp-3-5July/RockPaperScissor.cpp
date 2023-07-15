#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

double dp[105][105][105];

void setDp() {
	for (int i = 0; i < 105; ++i)
	{
		for (int j = 0; j < 105; ++j)
		{
			for (int k = 0; k < 105; ++k)
			{
				dp[i][j][k] = -1;
			}
		}
	}
}

double rockWin(int r, int s, int p) {
	// base case
	if (p == 0) return dp[r][s][p] = 1;
	if (r == 0 || s == 0) return dp[r][s][p] = 0;
	if (dp[r][s][p] != -1) return dp[r][s][p];
	// recursive case
	double ans = 0;
	double total = (r * p + p * s + r * s);
	// 1. Rock and Paper
	ans += rockWin(r - 1, s, p) * ((r * p) / total);
	// 2. Rock and Scissor
	ans += rockWin(r, s - 1, p) * ((r * s) / total);
	// 3. Paper and Scissor
	ans += rockWin(r, s, p - 1) * ((p * s) / total);
	return dp[r][s][p] = ans;
}

double paperWin(int r, int s, int p) {
	// base case
	if (s == 0) return dp[r][s][p] = 1;
	if (r == 0 || p == 0) return dp[r][s][p] = 0;
	if (dp[r][s][p] != -1) return dp[r][s][p];
	// recursive case
	double ans = 0;
	double total = (r * p + p * s + r * s);
	// 1. Rock and Paper
	ans += paperWin(r - 1, s, p) * ((r * p) / total);
	// 2. Rock and Scissor
	ans += paperWin(r, s - 1, p) * ((r * s) / total);
	// 3. Paper and Scissor
	ans += paperWin(r, s, p - 1) * ((p * s) / total);
	return dp[r][s][p] = ans;
}

double scissorWin(int r, int s, int p) {
	// base case
	if (r == 0) return dp[r][s][p] = 1;
	if (s == 0 || p == 0) return dp[r][s][p] = 0;
	if (dp[r][s][p] != -1) return dp[r][s][p];
	// recursive case
	double ans = 0;
	double total = (r * p + p * s + r * s);

	// 1. Rock and Paper
	ans += scissorWin(r - 1, s, p) * ((r * p) / total);
	// 2. Rock and Scissor
	ans += scissorWin(r, s - 1, p) * ((r * s) / total);
	// 3. Paper and Scissor
	ans += scissorWin(r, s, p - 1) * ((p * s) / total);
	return dp[r][s][p] = ans;
}


int main() {

	int t;
	cin >> t;


	while (t--) {
		int r = 2, s = 1, p = 2;
		cin >> r >> s >> p;
		// memset(dp, -1, sizeof dp);
		setDp();
		double op1 = rockWin(r, s, p);
		// memset(dp, -1, sizeof dp);
		setDp();
		double op2 = scissorWin(r, s, p);
		// memset(dp, -1, sizeof dp);
		setDp();
		double op3 = paperWin(r, s, p);
		cout << fixed << setprecision(9) << op1 << " " << op2 << " " << op3 << endl;

	}

	return 0;
}
















