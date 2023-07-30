#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <cmath>
#include <functional>
#include <deque>
#include <bitset>
#include <climits>
#include <cstdio>
#include <list>
#include <iomanip>
using namespace std;

#define ll long long int
#define int long long
#define new(a,n) ll*a = new ll[n]
#define new1(a,n,m) ll**a = new ll*[n]; for(ll i = 0 ; i < n ; i++) a[i] = new ll[m];
#define mp make_pair
#define pb push_back
#define fi first
#define pii pair<ll,ll>
#define si second
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define F(a,n) for(int i=0;i<n;i++){cin>>a[i];}
#define F1(a,n) for(int i=1;i<=n;i++){cin>>a[i];}
#define P(a,n) for(int i=0;i<n;i++){cout<<a[i]<<' ';}cout<<endl;
#define P1(a,n) for(int i=1;i<=n;i++){cout<<a[i]<<' ';}cout<<endl;
#define NF(a,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++){cin>>a[i][j];}}
#define NF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cin>>a[i][j];}}
#define PNF(a,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define PNF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define init(a,n,v) for(int i = 0 ; i <n ; i++) a[i]=v;
#define init2(a,n,m,v) for(int i=0;i<=n;i++){for(int j=0;j<=m;j++){a[i][j]=v;}}
#define AS 200001
#define mod 1000000007


int n, x, y, z;

int cnt[200005], ans = 0;

int holi(int node, unordered_map<int, bool> &visited,
         unordered_map<int, list< pair<int, int> > > &adj) {
	visited[node] =  true;
	cnt[node] = 1;
	for (auto p : adj[node]) {
		int ch = p.first;
		int wt = p.second;
		if (!visited[ch]) {
			cnt[node] += holi(ch, visited, adj);

			int op1 = cnt[ch];
			int op2 = n - op1;
			ans += min(op1, op2) * 2 * wt;
		}
	}

	return cnt[node];
}

int solve() {
	ans = 0;
	cin >> n;
	unordered_map<int, bool> visited;
	unordered_map<int, list< pair<int, int> > > adj;
	for (int i = 0; i < n - 1; ++i)
	{
		cin >> x >> y >> z;
		adj[x].pb({y, z});
		adj[y].pb({x, z});
		// cnt[i] = 1;
	}

	// cnt[n - 1] = cnt[n] = 1;

	holi(1, visited, adj);
	return ans;
}

int32_t main() {
	fastIO
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;
	cin >> t;

	for (int i = 1; i <= t; ++i)
	{
		cout << "Case #" << i << ": " << solve() << endl;
	}

	return 0;
}











