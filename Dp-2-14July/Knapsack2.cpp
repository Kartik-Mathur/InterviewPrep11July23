#include <iostream>
#include <vector>
using namespace std;
#define ll long long

ll N, capacity;
ll price[105], weight[105];
ll total_profit = 0;
ll inf = 1e9;

ll solve() {

	vector< vector<ll> > dp(N + 1, vector<ll> (total_profit + 1));
	for (ll row = 0 ; row <= N ; row++) {
		dp[row][0] = 0;
	}

	for (ll col = 1; col <= total_profit ; col++) {
		dp[0][col] = inf;
	}

	for (ll n = 1; n <= N ; n++) {
		for (ll p = 1 ; p <= total_profit ; p++) {
			ll op1, op2;
			op1 = op2 = inf;
			if (p >= price[n - 1]) {
				op1 = weight[n - 1] + dp[n - 1][p - price[n - 1]];
			}
			op2 = 0 + dp[n - 1][p];
			dp[n][p] = min(op1, op2);
		}
	}

	ll ans = 0;
	for (ll i = 1 ; i <= total_profit; i++) {
		if (dp[N][i] <= capacity) ans = i;
	}

	return ans;

}


int main() {

	cin >> N >> capacity;
	for (int i = 0; i < N; ++i)
	{
		cin >> weight[i] >> price[i];
		total_profit += price[i];
	}

	cout << solve() << endl;


	return 0;
}
















