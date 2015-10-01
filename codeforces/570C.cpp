#include <bits/stdc++.h>
using namespace std;

const int kM = 300010;

int N, M, X[kM];
char C[kM];
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
  cin >> N >> M >> S;
  for (int i = 0; i < M; ++i)
    cin >> X[i] >> C[i];
}

void solve() {
  static int res[kM];
  int num_p = 0, num_s = 0;

  S = "#" + S + "#";
  for (int i = 1, c = 0; i <= N; ++i) {
    if (S[i] == '.') {
      ++num_p, ++c;
      if (c == 1)
        ++num_s;
    }
    else
      c = 0;
  }

  for (int i = 0; i < M; ++i) {
    if (C[i] == '.' && S[X[i]] != '.') {
      ++num_p;
      if (S[X[i] - 1] == '.' && S[X[i] + 1] == '.') --num_s;
      if (S[X[i] - 1] != '.' && S[X[i] + 1] != '.') ++num_s;
    }
    else if (C[i] != '.' && S[X[i]] == '.') {
      --num_p;
      if (S[X[i] - 1] == '.' && S[X[i] + 1] == '.') ++num_s;
      if (S[X[i] - 1] != '.' && S[X[i] + 1] != '.') --num_s;
    }

    S[X[i]] = C[i], res[i] = num_p - num_s;
  }

  for (int i = 0; i < M; ++i)
    cout << res[i] << "\n";
}
