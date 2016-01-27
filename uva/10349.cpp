// 10349. Antenna Placement

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
const int kH = 45;
const int kW = 15;
const int kV = kH * kW;
const pair< int, int > kDir[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int Z, H, W;
char P[kH][kW];

vector< int > g[kV];
int my[kV], xs, ys;
bool vy[kV];

void read();
void solve();

bool dfs(int);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> Z;
	for (int zi = 1; zi <= Z; ++zi)
		read(), solve();

	return 0;
}

void read() {
	cin >> H >> W;
	fill(&P[0][0], &P[H + 2][0], 'o');
	for (int i = 1; i <= H; ++i)
		for (int j = 1; j <= W; ++j)
			cin >> P[i][j];
}

void solve() {
	static int num[kH][kW];
	int res;

	xs = (H * W + 1) / 2, ys = H * W - xs;
	for (int i = 0; i < xs; ++i)
		g[i].clear();

	res = 0;
	for (int i = 1, c = 0; i <= H; ++i)
		for (int j = 1; j <= W; ++j, ++c) {
			num[i][j] = c / 2;
			res += int(P[i][j] == '*');
		}

	for (int i = 1; i <= H; ++i)
		for (int j = 1 + (~i & 1); j <= W; j += 2)
			if (P[i][j] == '*') {
				for (auto &p: kDir) {
					if (P[i + p.fr][j + p.sc] == '*')
						g[num[i][j]].phb(num[i + p.fr][j + p.sc]);
				}
			}

	fill(&my[0], &my[ys], -1);
	for (int i = 0; i < xs; ++i) {
		fill(&vy[0], &vy[ys], false);
		if (dfs(i))
			--res;
	}

	cout << res << "\n";
}

bool dfs(int u) {
	int w;
	for (int v: g[u])
		if (!vy[v]) {
			vy[v] = true;
			if ((w = my[v]) == -1 || dfs(w)) {
				my[v] = u;
				return true;
			}
		}
	return false;
}
