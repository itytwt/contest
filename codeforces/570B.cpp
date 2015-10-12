// 570B. Simple Game

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

int N, M;

void solve();

int main() {
	ios::sync_with_stdio(false);
	cin >> N >> M;
	solve();
	return 0;
}

void solve() {
	if (N == 1)
		cout << "1\n";
	else
		cout << (M - 1 >= N - M ? M - 1 : M + 1) << "\n";
}
