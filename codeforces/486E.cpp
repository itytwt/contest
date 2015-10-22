// 486E. LIS of Sequence

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
const int kN = 100010;

int N, Ai[kN];

int f1[kN], f2[kN];
vector< int > p[kN];
int res[kN];

void read();
void solve();

int main() {
	ios::sync_with_stdio(false);
	read();
	solve();
	return 0;
}

void read() {
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> Ai[i];
}

void solve() {
	int lis;

	vector< int > v;
	for (int i = 0; i < N; ++i) {
		int q = int(lower_bound(all(v), Ai[i]) - v.begin());
		if (q == sz(v)) v.phb(0);
		v[q] = Ai[i], f1[i] = q + 1;
	}
	lis = sz(v);

	v.clear();
	for (int i = N - 1; i >= 0; --i) {
		int q = int(lower_bound(all(v), Ai[i], greater< int >()) - v.begin());
		if (q == sz(v)) v.phb(0);
		v[q] = Ai[i], f2[i] = q + 1;
	}

	for (int i = 0; i < N; ++i)
		if (f1[i] + f2[i] == lis + 1)
			p[f1[i]].phb(i);

	fill(&res[0], &res[N], 1);
	for (int i = 1; i <= lis; ++i) {
		if (sz(p[i]) == 1)
			res[p[i][0]] = 3;
		else {
			for (int k: p[i])
				res[k] = 2;
		}
	}

	for (int i = 0; i < N; ++i)
		cout << res[i];
	cout << "\n";
}
