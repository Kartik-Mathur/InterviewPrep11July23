class Solution {
public:
	unordered_map<int, list<int> > adj;
	int count[40000];
	int stSum[40000];
	vector<int> dp;
	int N;
	void cntStandNode(int node, int parent) {
		for (auto ch : adj[node]) {
			if (ch != parent) {
				cntStandNode(ch, node);
				count[node] += count[ch];
				stSum[node] += stSum[ch] + count[ch];
			}
		}
	}

	void solve(int node, int parent) {
		for (auto ch : adj[node]) {
			if (ch != parent) {

				dp[ch] = dp[node] - count[ch] + N - count[ch];
				solve(ch, node);
			}
		}
	}


	vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
		for (auto e : edges) {
			adj[e[0]].push_back(e[1]);
			adj[e[1]].push_back(e[0]);
		}
		for (int i = 0; i < n; ++i)
		{
			count[i] = 1;
		}
		N = n;
		dp.resize(n);
		cntStandNode(0, -1);
		dp[0] = stSum[0];
		solve(0, -1);
		return dp;
	}
};









