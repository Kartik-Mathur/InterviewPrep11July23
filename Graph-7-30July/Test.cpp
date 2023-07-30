// https://codeforces.com/problemset/problem/1286/B
#include <bits/stdc++.h>
using namespace std;
int c[2005];
vector<list<int> > adj(2005);

vector<int> solve(int root) {
	vector<int> v;
	for (auto ch : adj[root]) {
		vector<int> x = solve(ch);
		for (auto e : x) {
			v.push_back(e);
		}
	}

	if (v.size() < c[root]) {
		cout  << "NO\n";
		exit(0);
	}
	v.insert(v.begin() + c[root], root);
	return v;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, root;
	cin >> n;

	for (int i = 1; i <= n; ++i)
	{
		int parent;
		cin >> parent >> c[i];
		adj[parent].push_back(i);
		if (parent == 0) {
			root = i;
		}
	}

	vector<int> x = solve(root);
	vector<int> ans(n + 1);
	for (int i = 0; i < x.size(); ++i)
	{
		ans[x[i]] = i + 1;
	}
	cout << "YES\n";
	for (int i = 1; i <= n; ++i)
	{
		cout << ans[i] << " ";
	}
	cout << endl;


	return 0;
}















