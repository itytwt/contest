// 4610. Common Subexpression Elimination

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
typedef pair< int, int > pii;
typedef pair< string, pii > psp;
const int kN = 50010;

struct Node {
  int ch[2];
  string t;

  void clear() {
    ch[0] = ch[1] = 0, t = "";
  }
} tree[kN];

int Z;
string S;

int pos, dfi;
map< psp, int > m;
int tid[kN], gid[kN];

void solve();

int dfs1();
void dfs2(int);
void dfs3(int, ostringstream &);

int main() {
  ios::sync_with_stdio(false);
  cin >> Z;
  for (int zi = 1; zi <= Z; ++zi)
    cin >> S, solve();

  return 0;
}

void solve() {
  pos = dfi = 0, dfs1();
  m.clear(), dfs2(1);

  ostringstream oss;
  dfi = 0, dfs3(1, oss);
  cout << oss.str() << "\n";
}

int dfs1() {
  int u = ++dfi;

  tree[u].clear();
  while (pos < sz(S) && isalpha(S[pos]))
    tree[u].t += S[pos++];

  if (pos < sz(S) && S[pos] == '(') {
    for (int i = 0; i < 2; ++i)
      ++pos, tree[u].ch[i] = dfs1();
    ++pos; // closing bracket
  }

  return u;
}

void dfs2(int u) {
  if (u) {
    for (int i = 0; i < 2; ++i)
      dfs2(tree[u].ch[i]);

    psp p = mkp(tree[u].t, mkp(tid[tree[u].ch[0]], tid[tree[u].ch[1]]));
    if (!m.count(p))
      m[p] = u;
    tid[u] = m[p];
  }
}

void dfs3(int u, ostringstream &oss) {
  if (u == tid[u]) {
    gid[u] = ++dfi;
    oss << tree[u].t;
    if (tree[u].ch[0]) {
      oss << "(";
      dfs3(tree[u].ch[0], oss);
      oss << ",";
      dfs3(tree[u].ch[1], oss);
      oss << ")";
    }
  }
  else
    oss << gid[tid[u]];
}
