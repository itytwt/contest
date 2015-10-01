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
const int kN = 110;

int N, M, V[kN][kN];

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
  for (int i = 0; i < M; ++i)
    for (int j = 0; j < N; ++j)
      cin >> V[i][j];
}

void solve() {
  vector< int > c(N, 0);
  for (int i = 0; i < M; ++i)
    ++c[int(max_element(&V[i][0], &V[i][N]) - &V[i][0])];
  cout << (int(max_element(all(c)) - c.begin()) + 1) << "\n";
}
