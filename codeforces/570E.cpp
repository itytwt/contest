#include <bits/stdc++.h>
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define mkp make_pair
#define phb push_back
#define ppf pop_front
#define fr first
#define sc second
using namespace std;

typedef long long ll;
typedef pair< int, int > pii;
const int kMod = 1000000007;
const int kN = 510;

int N, M;
char C[kN][kN];

void read();
void solve();

int main() {
	ios::sync_with_stdio(false);
	read();
	solve();
	return 0;
}

void read() {
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			cin >> C[i][j];
}

void solve() {
	static pii off[] = {{1, 0}, {0, 1}};
	static int f[2][kN][kN];
	int lf = (N + M - 2) / 2, rf = (N + M - 1) / 2;
	int x1, y1, x2, y2, nx1, ny1, nx2, ny2;

	auto is_valid = [&] (const int &x, const int &y) -> bool { return ((0 <= x) && (x < N)) && ((0 <= y) && (y < M)); };

	for (int i = 0; (x1 = min(N - 1, lf) - i) >= 0 && (y1 = lf - x1) < M; ++i)
		for (int j = 0; (x2 = min(N - 1, rf) - j) >= 0 && (y2 = rf - x2) < M; ++j)
			if (abs(x1 - x2) + abs(y1 - y2) <= 1 && C[x1][y1] == C[x2][y2])
				f[0][i][j] = 1;

	for (int k = 0; k < lf; ++k) {
		fill(&f[(k + 1) & 1][0][0], &f[((k + 1) & 1) + 1][0][0], 0);
		for (int i = 0; (x1 = min(N - 1, lf - k) - i) >= 0 && (y1 = lf - k - x1) < M; ++i)
			for (int j = 0; (x2 = min(N - 1, rf + k) - j) >= 0 && (y2 = rf + k - x2) < M; ++j)
				for (auto p: off)
				if (is_valid(nx1 = x1 - p.fr, ny1 = y1 - p.sc))
					for (auto q: off)
					if (is_valid(nx2 = x2 + q.fr, ny2 = y2 + q.sc))
						if (C[nx1][ny1] == C[nx2][ny2]) {
							int ni = min(N - 1, lf - k - 1) - nx1, nj = min(N - 1, rf + k + 1) - nx2;
							f[(k + 1) & 1][ni][nj] = (f[(k + 1) & 1][ni][nj] + f[k & 1][i][j]) % kMod;
						}
	}

	cout << f[lf & 1][0][0] << "\n";
}
