// 6036. Stacking Plates

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
const int kInf = numeric_limits< int >::max() / 2;
const int kN = 50;
const int kH = 50;
const int kVal = 10010;

int Z, N;
vector< int > S[kN];

void read();
void solve();

int main() {
  ios::sync_with_stdio(false);
  while (cin >> N)
    read(), solve();

  return 0;
}

void read() {
  int h, s;
  for (int i = 0; i < N; ++i) {
    cin >> h, S[i].clear();
    for (int j = 0; j < h; ++j)
      cin >> s, S[i].phb(s);
  }
}

void solve() {
  static int zi;
  static bool hs[kN][kVal]; // has size
  static int f[kN][kN * kH + 10];
  vector< int > ds; // distinct size

  fill(&hs[0][0], &hs[N][0], false);
  for (int i = 0; i < N; ++i)
    for (int v: S[i])
      ds.phb(v), hs[i][v] = true;
  sort(all(ds)), reverse(all(ds));
  ds.erase(unique(all(ds)), ds.end());

  fill(&f[0][0], &f[N][0], kInf);
  for (int i = 0; i < N; ++i)
    f[i][0] = 0;

  for (int i = 0; i < sz(ds); ++i)
    for (int j = 0; j < N; ++j)
      if (f[j][i] != kInf) {
        ll st = 0;
        for (int k = 0; k < N; ++k)
          if (hs[k][ds[i]])
            st |= (ll(1) << k);

        int n = __builtin_popcountll(st);
        for (int k = 0; k < N; ++k)
          if (hs[k][ds[i]]) {
            if (n == 1)
              f[k][i + 1] = min(f[k][i + 1], f[j][i] + int(j != k));
            else {
              st ^= (ll(1) << k);
              f[k][i + 1] = min(f[k][i + 1], f[j][i] + (((st >> j) & ll(1)) ? n - 1 : n));
              st ^= (ll(1) << k);
            }
          }
      }

  int sc = kInf;
  for (int i = 0; i < N; ++i)
    sc = min(sc, f[i][sz(ds)]);
  cout << "Case " << (++zi) << ": " << (2 * sc - N + 1) << "\n";
}
