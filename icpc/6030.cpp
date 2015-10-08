// 6030. Infiltration

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
typedef bitset< 75 > bvect;
const int kN = 75;

int N;
string C[kN];

bvect mask[kN], goal;
vector< int > res;

void read();
void solve();

void dfs(int, const bvect &, vector< int > &);

int main() {
	ios::sync_with_stdio(false);
	while (cin >> N)
    read(), solve();

	return 0;
}

void read() {
  for (int i = 0; i < N; ++i)
    cin >> C[i];
}

void solve() {
  static int zi;

  for (int i = 0; i < N; ++i) {
    mask[i].reset();
    for (int j = 0; j < sz(C[i]); ++j)
      mask[i][j] = int(C[i][j] - '0');
    mask[i][i] = 1;
  }

  goal.reset();
  for (int i = 0; i < N; ++i)
    goal[i] = 1;

  vector< int > tmp;
  res = vector< int >(7);
  dfs(0, bvect(), tmp);

  cout << "Case " << (++zi) << ": " << sz(res);
  for (int v: res)
    cout << " " << v;
  cout << "\n";
}

void dfs(int beg, const bvect &cur, vector< int > &tmp) {
  if (cur == goal) {
    if (sz(tmp) < sz(res))
      res = tmp;
    return;
  }

  if (sz(tmp) >= sz(res))
    return;

  int rem = int((goal ^ cur).count());
  for (int i = beg; i < N; ++i)
    // should cut down by at least half,
    //  otherwise it is impossible to be a part of optimal solutions
    if (2 * int(((cur ^ mask[i]) & mask[i]).count()) >= rem) {
      tmp.phb(i + 1);
      dfs(i + 1, cur | mask[i], tmp);
      tmp.ppb();
    }
}
