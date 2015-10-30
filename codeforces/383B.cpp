// 383B. Volcanoes

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
typedef pair< int, int > pii;
const int kM = 100010;

int N, M, Xi[kM], Yi[kM];

void read();
void solve();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	read();
	solve();
	return 0;
}

void read() {
	cin >> N >> M;
	for (int i = 0; i < M; ++i)
		cin >> Xi[i] >> Yi[i];
}

void solve() {
	map< int, vector< int > > m;

	m[1].phb(N + 1), m[N].phb(N + 1);
	for (int i = 0; i < M; ++i) {
		m[Xi[i]].phb(N + 1), m[Xi[i]].phb(Yi[i]);
		if (Xi[i] > 1) m[Xi[i] - 1].phb(N + 1);
		if (Xi[i] < N) m[Xi[i] + 1].phb(N + 1);
	}

	vector< vector< int > > obs;
	for (auto &p: m) {
		vector< int > tmp(p.sc);
		sort(all(tmp));
		tmp.erase(unique(all(tmp)), tmp.end());
		obs.phb(tmp);
	}

	deque< pii > que[2];
	int p = 0, q = 1;

	que[q].phb({1, obs[0].front() - 1});
	for (int k = 0; k < sz(obs); ++k) {
		swap(p, q);
		que[q].clear();

		deque< pii > &qp = que[p], &qq = que[q];
		for (int i = 0; i < sz(qp); ) {
			int lb = int(lower_bound(all(obs[k]), qp[i].fr) - obs[k].begin());
			int rb = int(upper_bound(all(obs[k]), qp[i].sc) - obs[k].begin());
			if (lb < rb) {
				int s = qp[i].fr;
				for (int j = lb; j <= rb && s <= qp[i].sc; ++j) {
					if (s <= obs[k][j] - 1)
						qq.phb({s, obs[k][j] - 1});
					s = obs[k][j] + 1;
				}
				++i;
			}
			else {
				qq.phb({qp[i].fr, obs[k][lb] - 1});
				while (i < sz(qp) && qp[i].sc < obs[k][lb])
					++i;
			}
		}
	}

	cout << ((!que[q].empty() && que[q].back().sc == N) ? 2 * N - 2 : -1) << "\n";
}
