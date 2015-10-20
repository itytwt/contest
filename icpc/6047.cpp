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
const ll kQ = 3037000399LL;
const ll kP = 37;
const int kN = 1010;
const int kL = 510;

int Z, N;
string S[kN];

ll pw[kL];

void prep();
void read();
void solve(int);

int main() {
	ios::sync_with_stdio(false);
	prep();
	cin >> Z;
	for (int zi = 1; zi <= Z; ++zi)
		read(), solve(zi);

	return 0;
}

void prep() {
	pw[0] = 1;
	for (int i = 1; i < kL; ++i)
		pw[i] = pw[i - 1] * kP % kQ;
}

void read() {
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> S[i];
}

void solve(int zi) {
	static ll f1[kN], f2[kN];

	for (int i = 0; i < N; ++i) {
		f1[i] = f2[i] = 0;
		for (int j = 0; j < sz(S[i]); ++j)
			f1[i] = (f1[i] * kP % kQ + ll(S[i][j] - 'a') + 1) % kQ;
		for (int j = sz(S[i]) - 1; j >= 0; --j)
			f2[i] = (f2[i] * kP % kQ + ll(S[i][j] - 'a') + 1) % kQ;
	}

	int res = 0;
	for (int i = 0; i < N; ++i)
		for (int j = i + 1; j < N; ++j) {
			int si = sz(S[i]), sj = sz(S[j]);
			if ((f1[i] * pw[sj] % kQ + f1[j]) % kQ == (f2[j] * pw[si] % kQ + f2[i]) % kQ)
				++res;
			if ((f1[j] * pw[si] % kQ + f1[i]) % kQ == (f2[i] * pw[sj] % kQ + f2[j]) % kQ)
				++res;
		}

	cout << "Case #" << zi << ": " << res << "\n";
}
