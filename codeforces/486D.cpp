// 486D. Valid Sets

#include <bits/stdc++.h>
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define mkp make_pair
#define phb push_back
#define ppb pop_back
#define ppf pop_front
#define fr first
#define sc second
using namespace std;

typedef long long ll;
const ll kMod = 1000000007;
const int kN = 2010;

int N, D, Ai[kN];
vector< int > tree[kN];

void read();
void solve();

ll dfs(int, int, int);

int main() {
	ios::sync_with_stdio(false);
	read();
	solve();
	return 0;
}

void read() {
	cin >> D >> N;
	for (int i = 1; i <= N; ++i)
		cin >> Ai[i];

	int u, v;
	for (int i = 0; i < N - 1; ++i) {
		cin >> u >> v;
		tree[u].phb(v), tree[v].phb(u);
	}
}

void solve() {
	vector< int > ord;
	for (int i = 1; i <= N; i++)
		ord.phb(i);
	sort(all(ord), [&] (const int &a, const int &b) -> bool {
		if (Ai[a] != Ai[b])
			return Ai[a] < Ai[b];
		else
			return a < b;
	});

	ll res = 0;
	for (int r: ord)
		res = (res + dfs(r, 0, r)) % kMod;
	cout << res << "\n";
}

ll dfs(int u, int p, int r) {
	vector< ll > c;
	for (int v: tree[u])
		if (v != p) {
			if (Ai[v] <= Ai[r] + D && (Ai[v] > Ai[r] || (Ai[v] == Ai[r] && v > r)))
				c.phb(dfs(v, u, r));
		}

	ll ret = 1;
	for (ll k: c)
		ret = ret * (k + 1) % kMod;
	return ret;
}
