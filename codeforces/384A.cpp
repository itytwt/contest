// 384A. Coder

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
const int kN = 1010;

int N;

void solve();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	solve();

	return 0;
}

void solve() {
	static char p[kN][kN];
	int res = 0;

	fill(&p[0][0], &p[N + 1][0], '.');
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			if (p[i - 1][j] == '.' && p[i][j - 1] == '.')
				p[i][j] = 'C', ++res;

	cout << res << "\n";
	for (int i = 1; i <= N; ++i, cout << "\n")
		for (int j = 1; j <= N; ++j)
			cout << p[i][j];
}
