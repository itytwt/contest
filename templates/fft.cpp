// fast fourier transform
//  * rev: false = dft, true = idft
//  * sz(smp) must be power of 2

typedef complex< double > cplx;
const double kPi = acos(-1.0);

vector< cplx > fft(const vector< cplx > &smp, bool rev) {
  int n = sz(smp);
  vector< cplx > a(n), w(n);

  for (int i = 0; i < n; ++i) {
    int ni = 0;
    for (int j = 1, x = i; j < n; j <<= 1, x >>= 1)
      ni <<= 1, ni |= x & 1;
    a[ni] = smp[i];
  }

  for (int i = 0; i < n; ++i)
    w[i] = polar(1.0, (rev ? -1 : 1) * 2.0 * i * kPi / n);

  for (int k = 1; k < n; k <<= 1) {
    vector< cplx > y(n);
    for (int i = 0, s = n / (2 * k); i < n; i += 2 * k)
      for (int j = 0, p = i; j < k; ++j, ++p) {
        y[p] = a[p] + w[j * s] * a[p + k];
        y[p + k] = a[p] - w[j * s] * a[p + k];
      }
    a = y;
  }

  if (rev) {
    for (int i = 0; i < n; ++i)
      a[i] /= n;
  }

  return a;
}
