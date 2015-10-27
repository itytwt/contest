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
const int kN = 200010;
const int kL = 1 << 20;

int N, M, Ai[kN];
vector< int > tree[kN];

int lbs[kN], lbe[kN], dpt[kN];
vector< int > tour;

struct TNode {
	int val, lpv;
} st[2][kL];

void read();
void solve();

void dfs(int, int, int);
void st_insert(int, int, int, int, int, int, int);
int st_query(int, int, int, int, int);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	read();
	solve();
	return 0;
}

void read() {
	cin >> N >> M;
	for (int i = 1; i <= N; ++i)
		cin >> Ai[i];

	int u, v;
	for (int i = 0; i < N - 1; ++i) {
		cin >> u >> v;
		tree[u].phb(v), tree[v].phb(u);
	}
}

void solve() {
	dfs(1, 0, 0);
	int ts = 1 << (32 - __builtin_clz(sz(tour) - 1));
	int cmd, x, val;
	for (int i = 0; i < M; ++i) {
		cin >> cmd >> x;
		if (cmd == 1) {
			cin >> val;
			st_insert(dpt[x] & 1, 1, lbs[x], lbe[x] + 1, 0, ts, val);
			st_insert((dpt[x] & 1) ^ 1, 1, lbs[x], lbe[x] + 1, 0, ts, -val);
		}
		else
			cout << st_query(dpt[x] & 1, 1, lbs[x], 0, ts) + Ai[x] << "\n";
	}
}

void dfs(int u, int p, int d) {
	dpt[u] = d;
	lbs[u] = sz(tour);
	tour.phb(u);
	for (int v: tree[u])
		if (v != p)
			dfs(v, u, d + 1);
	lbe[u] = sz(tour);
	tour.phb(u);
}

void st_insert(int t, int u, int ql, int qr, int l, int r, int val) {
	TNode &tn = st[t][u];
	if (ql <= l && r <= qr)
		tn.val += val, tn.lpv += val;
	else {
		int mid = (l + r) / 2;
		if (tn.lpv != 0) {
			st_insert(t, 2 * u, l, mid, l, mid, tn.lpv);
			st_insert(t, 2 * u + 1, mid, r, mid, r, tn.lpv);
			tn.lpv = 0;
		}

		if (ql < mid) st_insert(t, 2 * u, ql, qr < mid ? qr : mid, l, mid, val);
		if (qr > mid) st_insert(t, 2 * u + 1, ql > mid ? ql : mid, qr, mid, r, val);
	}
}

int st_query(int t, int u, int q, int l, int r) {
	TNode &tn = st[t][u];
	if (l + 1 == r && q == l)
		return tn.val;
	else {
		int mid = (l + r) / 2;
		if (tn.lpv != 0) {
			st_insert(t, 2 * u, l, mid, l, mid, tn.lpv);
			st_insert(t, 2 * u + 1, mid, r, mid, r, tn.lpv);
			tn.lpv = 0;
		}

		if (q < mid)
			return st_query(t, 2 * u, q, l, mid);
		else
			return st_query(t, 2 * u + 1, q, mid, r);
	}
}
