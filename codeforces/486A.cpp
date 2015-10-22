// 486A. Calculating Function

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

int main() {
	ios::sync_with_stdio(false);

	ll N;
	cin >> N;
	cout << (N / 2 - (N % 2 == 0 ? 0 : N)) << "\n";

	return 0;
}
