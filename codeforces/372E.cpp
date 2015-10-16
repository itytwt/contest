// 372E. Drawing Circles is Fun

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
const ll kMod = 1000000007;

struct frac {
	ll a, b;

	frac() {
		a = 0, b = 1;
	}

	frac(ll _a) {
		a = _a, b = 1;
	}

	frac(ll _a, ll _b) {
		if (_b) {
			ll g = __gcd(_a, _b);
			a = _a / g, b = _b / g;
			if (b < 0) b = -b, a = -a;
		}
		else
			a = (_a > 0 ? 1 : -1), b = 0;
	}

	frac operator - () const {
		return frac(-(this->a), this->b);
	}

	frac operator + (const frac &that) const {
		return frac(this->a * that.b + this->b * that.a, this->b * that.b);
	}

	frac & operator += (const frac &that) {
		frac tmp = (*this) + that;
		tmp.swap(*this);
		return *this;
	}

	frac operator - (const frac &that) const {
		return (*this) + (-that);
	}

	frac & operator -= (const frac &that) {
		frac tmp = (*this) - that;
		tmp.swap(*this);
		return *this;
	}

	frac operator * (const frac &that) const {
		return frac(this->a * that.a, this->b * that.b);
	}

	frac & operator *= (const frac &that) {
		frac tmp = (*this) * that;
		tmp.swap(*this);
		return *this;
	}

	frac operator / (const frac &that) const {
		return frac(this->a * that.b, this->b * that.a);
	}

	frac & operator /= (const frac &that) {
		frac tmp = (*this) / that;
		tmp.swap(*this);
		return *this;
	}

	bool operator < (const frac &that) const {
		if ((this->a ^ that.a) < 0)
			return this->a < 0;
		else
			return this->a * that.b < this->b * that.a;
	}

	bool operator == (const frac &that) const {
		return !(*this < that) && !(that < *this);
	}

	void swap(frac &that) {
		std::swap(this->a, that.a);
		std::swap(this->b, that.b);
	}

	friend ostream & operator << (ostream &os, const frac &k) {
		os << k.a;
		if (k.b > 1) os << "/" << k.b;
		return os;
	}

};

typedef complex< frac > point;
typedef pair< point, frac > ppf;

int N;
int Ai[kN], Bi[kN], Ci[kN], Di[kN];

void read();
void solve();

int main() {
	ios::sync_with_stdio(false);
	read();
	solve();
	return 0;
}

void read() {
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> Ai[i] >> Bi[i] >> Ci[i] >> Di[i];
}

void solve() {
	auto lt_pt = [&] (const point &a, const point &b) -> bool {
		return imag(a) < imag(b) || (imag(a) == imag(b) && real(a) < real(b));
	};

	vector< point > pt;
	for (int i = 0; i < N; ++i) {
		frac x(Ai[i], Bi[i]), y(Ci[i], Di[i]);
		pt.phb(point(x / (x * x + y * y), y / (x * x + y * y)));
	}

	vector< ppf > vp;
	for (int i = 0; i < N; ++i)
		for (int j = i + 1; j < N; ++j) {
			if (imag(pt[j]) < imag(pt[i]))
				vp.phb({pt[i] + pt[j], (imag(pt[i]) - imag(pt[j])) / (real(pt[i]) - real(pt[j]))});
			else
				vp.phb({pt[i] + pt[j], (imag(pt[j]) - imag(pt[i])) / (real(pt[j]) - real(pt[i]))});
		}

	sort(all(vp), [&] (const ppf &a, const ppf &b) -> bool {
		if (!lt_pt(a.fr, b.fr) && !lt_pt(b.fr, a.fr))
			return a.sc < b.sc;
		else
			return lt_pt(a.fr, b.fr);
	});

	ll res = 0;
	for (int i = 0, j; i < sz(vp); i = j) {
		j = i + 1;
		while (j < sz(vp) && !lt_pt(vp[i].fr, vp[j].fr))
			++j;

		vector< ll > tmp;
		for (int p = i, q; p < j; p = q) {
			q = p + 1;
			while (q < j && !(vp[p].sc < vp[q].sc))
				++q;
			tmp.phb(ll(q - p));
		}

		ll mul = 1, sum = 0;
		for (ll t: tmp)
			mul = mul * (t + 1) % kMod, sum += t;
		res = (res + (mul - sum - 1) % kMod) % kMod;
	}

	cout << (res % kMod + kMod) % kMod << "\n";
}
