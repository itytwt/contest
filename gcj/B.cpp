#include <bits/stdc++.h>
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define mkp make_pair
#define mkt make_tuple
#define phb push_back
#define ppb pop_back
#define ppf pop_front
#define fr first
#define sc second
using namespace std;

typedef long long ll;

int Z;
ll N;

void solve(int);
bool is_tidy(ll);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> Z;
	for (int zi = 1; zi <= Z; ++zi) {
		cin >> N;
		solve(zi);
	}

	return 0;
}

void solve(int zi) {
	ll n;
	static int arr[20], len;

	n = N;
	len = 0;
	while (n > 0LL)
		arr[len++] = int(n % 10LL), n /= 10LL;

	if (is_tidy(N)) {
		cout << "Case #" << zi << ": " << N << "\n";
		return;
	}

	ll res = 0LL;
	for (int i = 0; i < len; ++i) {
		if (arr[i] == 0)
			continue;

		ll tmp = 0LL;
		for (int j = len - 1; j >= 0; --j) {
			tmp *= 10LL;
			tmp += j > i ? arr[j] : (j == i ? arr[j] - 1 : 9);
		}

		if (is_tidy(tmp)) {
			res = tmp;
			break;
		}
	}

	cout << "Case #" << zi << ": " << res << "\n";
}

bool is_tidy(ll x) {
	ll tx = x;
	int pre = 9, cur;

	while (tx > 0LL) {
		cur = int(tx % 10LL), tx /= 10LL;
		if (cur > pre)
			return false;
		pre = cur;
	}

	return true;
}
