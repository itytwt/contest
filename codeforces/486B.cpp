// 486B. OR in Matrix

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
const int kN = 110;

int N, M, B[kN][kN];
int A[kN][kN];

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
			cin >> B[i][j];
}

void solve() {
	static int A[kN][kN];

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			A[i][j] = 1;

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			if (B[i][j] == 0) {
				for (int k = 0; k < M; ++k) A[i][k] = 0;
				for (int k = 0; k < N; ++k) A[k][j] = 0;
			}

	auto check = [&] () -> bool {
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j) {
				int t = 0;
				for (int k = 0; k < M; ++k) t |= A[i][k];
				for (int k = 0; k < N; ++k) t |= A[k][j];

				if (t != B[i][j])
					return false;
			}

		return true;
	};

	if (!check())
		cout << "NO\n";
	else {
		cout << "YES\n";
		for (int i = 0; i < N; ++i, cout << "\n")
			for (int j = 0; j < M; ++j) {
				if (j > 0) cout << " ";
				cout << A[i][j];
			}
	}
}
