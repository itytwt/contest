// 486C. Palindrome Transformation

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
const int kInf = numeric_limits< int >::max();

int N, P;
string S;

void read();
void solve();

int main() {
	ios::sync_with_stdio(false);
	read();
	solve();
	return 0;
}

void read() {
	cin >> N >> P >> S;
}

void solve() {
	--P;
	if (P >= (N + 1) / 2)
		reverse(all(S)), P = N - 1 - P;

	int res = 0;
	vector< int > v;

	for (int i = 0; i < N / 2; ++i)
		if (S[i] != S[N - 1 - i]) {
			int mn = int(min(S[i] - 'a', S[N - 1 - i] - 'a'));
			int mx = int(max(S[i] - 'a', S[N - 1 - i] - 'a'));
			res += min(mx - mn, mn + 26 - mx);
			v.phb(i);
		}

	if (!v.empty()) {
		if (P <= v.front())
			res += v.back() - P;
		else if (P >= v.back())
			res += P - v.front();
		else
			res += min(P + v.back() - 2 * v.front(), 2 * v.back() - P - v.front());
	}

	cout << res << "\n";
}
