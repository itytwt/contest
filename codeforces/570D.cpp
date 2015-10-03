// 570D. Tree Requests

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
const int kN = 500010;
const int kM = 500010;

int N, M, P[kN], V[kM], H[kM];
string S;

int D[kN], B[kN], E[kN];
vector< int > T[kN], tb[kN], te[kN];
vector< vector< int > > wf[kN];
int dfi;

void read();
void solve();

void dfs(int, int);

int main() {
	ios::sync_with_stdio(false);
	read();
	solve();
	return 0;
}

void read() {
  cin >> N >> M;
  for (int i = 2; i <= N; ++i)
    cin >> P[i];
  cin >> S;
  for (int i = 0; i < M; ++i)
    cin >> V[i] >> H[i];
}

void solve() {
  static bool res[kM];

  S = "#" + S;
  for (int i = 2; i <= N; ++i)
    T[P[i]].phb(i);
  dfs(1, 1);

  for (int qi = 0; qi < M; ++qi) {
    int v = V[qi], h = H[qi];
    if (h <= D[v]) {
      res[qi] = true;
      continue;
    }

    int l = int(lower_bound(all(tb[h]), B[v]) - tb[h].begin()) - 1;
    int r = int(lower_bound(all(te[h]), E[v]) - te[h].begin()) - 1;

    if (l >= r) {
      res[qi] = true;
      continue;
    }

    int oc = 0;
    for (int i = 0; i < 26; ++i)
      if ((wf[h][r][i] - wf[h][l][i]) % 2 == 1)
        ++oc;
    res[qi] = (oc < 2);
  }

  for (int i = 0; i < M; ++i)
    cout << (res[i] ? "Yes" : "No") << "\n";
}

void dfs(int u, int dpt) {
  if (tb[dpt].empty()) {
    tb[dpt].phb(0);
    te[dpt].phb(0);
    wf[dpt].phb(vector< int >(26));
  }

  D[u] = dpt;
  tb[dpt].phb(B[u] = ++dfi);
  wf[dpt].phb(wf[dpt].back());
  ++wf[dpt].back()[int(S[u] - 'a')];
  for (int v: T[u])
    dfs(v, dpt + 1);
  te[dpt].phb(E[u] = ++dfi);
}
