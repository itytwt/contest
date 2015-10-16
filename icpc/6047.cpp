// 6047. Perfect Matching

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
const int kN = 1010;
const int kL = 510;

struct TNode {
	int ch[26];
	bool has;

	void clear() {
		fill(&ch[0], &ch[26], -1), has = false;
	}
} tree1[kN * kL], tree2[kN * kL];

int Z, N;
string S[kN];

int tr_cnt1, tr_cnt2;
int f[2 * kL];

void read();
void solve(int);

void ins_str(const string &, TNode [], int &);
void manacher(const string &);

int main() {
	ios::sync_with_stdio(false);
	cin >> Z;
	for (int zi = 1; zi <= Z; ++zi)
		read(), solve(zi);

	return 0;
}

void read() {
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> S[i];
}

void solve(int zi) {
	tree1[0].clear(), tree2[0].clear(), tr_cnt1 = tr_cnt2 = 1;
	for (int i = 0; i < N; ++i) {
		reverse(all(S[i]));
		ins_str(S[i], tree1, tr_cnt1);
		reverse(all(S[i]));
		ins_str(S[i], tree2, tr_cnt2);
	}

	int res = 0, u;
	for (int i = 0; i < N; ++i) {
		manacher(S[i]);

		u = 0;
		for (int j = 0; j < sz(S[i]); ++j) {
			int ci = int(S[i][j] - 'a');
			if (tree1[u].ch[ci] == -1)
				break;
			u = tree1[u].ch[ci];
			if (tree1[u].has && f[sz(S[i]) + j + 2] >= (sz(S[i]) - j - 1))
				++res;
		}

		u = 0;
		for (int j = 0; j < sz(S[i]) - 1; ++j) {
			int ci = int(S[i][sz(S[i]) - j - 1] - 'a');
			if (tree2[u].ch[ci] == -1)
				break;
			u = tree2[u].ch[ci];
			if (tree2[u].has && f[sz(S[i]) - j] >= (sz(S[i]) - j - 1))
				++res;
		}

		// palindrome concatenating itself will be counted, exclude it
		if (f[sz(S[i]) + 1] >= sz(S[i]))
			--res;
	}

	cout << "Case #" << zi << ": " << res << "\n";
}

void ins_str(const string &t, TNode tree[], int &tr_cnt) {
	int u = 0;
	for (int i = 0; i < sz(t); ++i) {
		int ci = int(t[i] - 'a');
		if (tree[u].ch[ci] == -1)
			tree[tr_cnt].clear(), tree[u].ch[ci] = tr_cnt, ++tr_cnt;
		u = tree[u].ch[ci];
	}
	tree[u].has = true;
}

void manacher(const string &s) {
	string t = "^";
	int c, r;

	for (int i = 0; i < sz(s); ++i)
		t += "#", t += s[i];
	t += "#$";

	fill(&f[0], &f[2 * sz(s) + 3], 0);
	f[0] = c = r = 0;
	for (int i = 1; i < sz(t) - 1; ++i) {
		int mr = c - (i - c);

		f[i] = (r >= i ? min(f[mr], r - i) : 0);
		while (t[i + (f[i] + 1)] == t[i - (f[i] + 1)])
			++f[i];

		if (i + f[i] > r)
			c = i, r = i + f[i];
	}
}
