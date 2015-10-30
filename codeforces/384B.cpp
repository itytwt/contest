// 384B. Multitasking

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
const int kM = 110;

int N, M, K, A[kN][kM];

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
	cin >> N >> M >> K;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			cin >> A[i][j];
}

void solve() {
	cout << M * (M - 1) / 2 << "\n";
	if (K == 0) {
		for (int i = 1; i <= M; ++i)
			for (int j = i + 1; j <= M; ++j)
				cout << i << " " << j << "\n";
	}
	else {
		for (int i = M; i >= 1; --i)
			for (int j = i - 1; j >= 1; --j)
				cout << i << " " << j << "\n";
	}
}
