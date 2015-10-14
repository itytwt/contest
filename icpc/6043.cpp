// 6043. Knots

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
const int kP = 5010;

int Z, L, P;
int Ai[kP], Bi[kP];

void read();
void solve(int);

int main() {
	ios::sync_with_stdio(false);
	cin >> Z;
	for (int zi = 1; zi <= Z; ++zi)
		read(), solve(zi);

	return 0;
}

void read() {
	cin >> L >> P;
	for (int i = 0; i < P; ++i)
		cin >> Ai[i] >> Bi[i];
}

void solve(int zi) {
	vector< int > vr;
	static int ai[kP], bi[kP];
	static int nxt[2 * kP], prv[2 * kP];
	static int knot[2 * kP];
	static bool dm[2 * kP];

	auto rm = [&] (int i) -> void {
		prv[nxt[i]] = prv[i];
		nxt[prv[i]] = nxt[i];
	};

	for (int i = 0; i < P; ++i)
		vr.phb(Ai[i]), vr.phb(Bi[i]);
	sort(all(vr));
	for (int i = 0; i < P; ++i) {
		ai[i] = int(lower_bound(all(vr), Ai[i]) - vr.begin());
		bi[i] = int(lower_bound(all(vr), Bi[i]) - vr.begin());
	}

	fill(&dm[0], &dm[2 * kP], false);
	for (int i = 0; i < 2 * P; ++i)
		nxt[i] = i + 1, prv[i] = i - 1;
	nxt[2 * P - 1] = 0, prv[0] = 2 * P - 1;

	for (int i = 0; i < P; ++i)
		knot[ai[i]] = bi[i], knot[bi[i]] = -1;

	int kc = P;
	for (int fc = 0, p = 0; kc > 0 && fc < P; p = nxt[p]) {
		if (dm[p])
			rm(p);
		else if (knot[p] != -1) {
			while (dm[prv[p]])
				rm(prv[p]);

			if (knot[p] == nxt[p] || knot[p] == prv[p])
				dm[p] = dm[knot[p]] = true, fc = 0, --kc;
			else if (knot[prv[p]] != -1 && (nxt[knot[p]] == knot[prv[p]] || nxt[knot[prv[p]]] == knot[p]))
				dm[p] = dm[knot[p]] = dm[prv[p]] = dm[knot[prv[p]]] = true, fc = 0, kc -= 2;
			else
				++fc;
		}
	}

	cout << "Case #" << zi << ": " << (kc == 0 ? "YES" : "NO") << "\n";
}
