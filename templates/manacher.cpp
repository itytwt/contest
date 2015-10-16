// manacher's algorithm
//  * kL = max. input string length

int f[2 * kL + 3];

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
