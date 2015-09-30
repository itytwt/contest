#include <bits/stdc++.h>
using namespace std;

const int kN = 110;

int Z, N, S[kN];

int li, lex, ri, rex, tex;
int f[4][kN][kN];

void read();
void solve();

void set_parm();
int dp(int, int, int);

int main() {
  ios::sync_with_stdio(false);
  cin >> Z;
  for (int zi = 1; zi <= Z; ++zi)
    read(), solve();

  return 0;
}

void read() {
  cin >> N;
  for (int i = 0; i < N; ++i)
    cin >> S[i];
}

void solve() {
  set_parm();
  fill(&f[0][0][0], &f[4][0][0], -1);
  cout << (dp((li ? 2 : 0) | (ri ? 1 : 0), 0, tex) ? "Alice" : "Bob") << "\n";
}

void set_parm() {
  int k = int(find(&S[0], &S[N], 1) - &S[0]);

  li = lex = 0;
  for (int i = k - 1; i >= 0 && S[i] > S[i + 1]; --i) ++li;
  for (int i = k - li - 1; i >= 0 && S[i] < S[i + 1]; --i) ++lex;
  ri = rex = 0;
  for (int i = k + 1; i < N && S[i] > S[i - 1]; ++i) ++ri;
  for (int i = k + ri + 1; i < N && S[i] < S[i - 1]; ++i) ++rex;
  tex = N - 1 - li - lex - ri - rex;
}

int dp(int lr, int lri, int ex) {
  if (lr == 0 && lri == 0)
    return 1;

  if (~f[lr][lri][ex])
    return f[lr][lri][ex];

  f[lr][lri][ex] = 0;
  if ((lr & 2) && !dp(lr ^ 2, lri + li - 1, ex + lex))
    f[lr][lri][ex] = 1;
  if ((lr & 1) && !dp(lr ^ 1, lri + ri - 1, ex + rex))
    f[lr][lri][ex] = 1;
  if (lri > 0 && !dp(lr, lri - 1, ex))
    f[lr][lri][ex] = 1;
  if (ex > 0 && !dp(lr, lri, ex - 1))
    f[lr][lri][ex] = 1;
  return f[lr][lri][ex];
}
