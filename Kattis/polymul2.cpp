#include<bits/stdc++.h>
using namespace std;
typedef complex<double> cd;
typedef long double ld;

void fft(vector<cd> &A, bool invert) {
  int n = A.size();

  for (int i = 1, j = 0; i < n; i++) {
    int bit = (n >> 1);
    for (; j & bit; bit >>= 1) j ^= bit;
    j ^= bit;
    if (i < j) swap(A[i], A[j]);
  }

  for (int cn = 2; cn <= n; cn <<= 1) {
    ld ang = 2*M_PIl/cn * (invert ? -1 : 1);
    cd wcn(cosl(ang), sinl(ang));
    for (int i = 0; i < n; i += cn) {
      cd w(1);
      for (int j = 0; j < cn/2; j++) {
        cd u = A[i+j], v = A[i+j+cn/2]*w;
        A[i+j] = u+v;
        A[i+j+cn/2] = u-v;
        w *= wcn;
      }
    }
  }
  if (invert) for (cd &x : A) x /= n;
}

vector<int> multiply(vector<int> p1, vector<int> p2) {
  int n = 1;
  int deg = p1.size() + p2.size() - 1;
  while (n < deg) n <<= 1;
  vector<cd> A(p1.begin(), p1.end());
  vector<cd> B(p2.begin(), p2.end());
  A.resize(n); B.resize(n);
  fft(A, false); fft(B, false);
  vector<cd> C(n);
  for (int k = 0; k < n; k++)
    C[k] = A[k]*B[k];
  fft(C, true);

  vector<int> res;
  for (auto &p : C) res.push_back(round(p.real()));
  res.resize(deg);
  return res;
}

int main() {
  cin.tie(0)->sync_with_stdio(false);

  int t; cin >> t;
  int n; cin >> n;
  vector<int> a(n+1);
  for (int &x : a) cin >> x;

  int m; cin >> m;
  vector<int> b(m+1);
  for (int &x : b) cin >> x;

  vector<int> c = multiply(a, b);
  int sz = c.size();
  cout << sz-1 << "\n";
  for (int i = 0; i < sz; i++) {
    cout << c[i] << " \n"[i+1==sz];
  }
  return 0;
}