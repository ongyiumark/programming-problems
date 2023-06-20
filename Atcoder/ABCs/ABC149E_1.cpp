#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<int,pair<int,int>> iii;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

struct poly {
  ld a, b;
  poly(ld a=0, ld b=0) : a(a), b(b) {}
  poly operator+(const poly &z) {
    return poly(a+z.a, b+z.b);
  }
  poly operator-(const poly &z) {
    return poly(a-z.a, b-z.b);
  }
  poly operator*(const poly &z) {
    return poly(a*z.a-b*z.b, a*z.b+b*z.a);
  }
};

void fft(vector<poly> &in, vector<poly> &p, int n, int s, int start_in, int start_p) {
  if (n < 1) return;
  if (n == 1) {
    p[start_p] = in[start_in];
    return;
  }

  n >>= 1; fft(in, p, n, s << 1, start_in, start_p);
  fft(in, p, n, s << 1, start_in+s, start_p+n);
  poly w(1), wn(cos(M_PI/n), sin(M_PI/n));
  for (int i = 0; i < n; i++) {
    poly even = p[start_p+i], odd = p[start_p+i+n];
    p[start_p+i] = even + w*odd;
    p[start_p+i+n] = even - w*odd;
    w = w*wn;
  }
}

void fft(vector<poly> &p) {
  int n = p.size();
  vector<poly> f(n); fft(p, f, n, 1, 0, 0);
  for (int i = 0; i < n; i++) p[i] = f[i];
}

void inverse_fft(vector<poly> &p) {
  int n = p.size();
  for (int i = 0; i < n; i++) p[i].b *= -1;
  fft(p);
  for (int i = 0; i < n; i++) {
    p[i].a /= n;
    p[i].b /= -1*n;
  }
}

vector<ll> mult(vector<ll> &a, vector<ll> &b) {
  int an = a.size(), bn = b.size();
  int n, deg = an+bn-1;
  vector<ll> C(deg);
  for (n = 1; n < deg; n <<= 1);
  vector<poly> A(n), B(n);
  for (int i = 0; i < n; i++) {
    if (i < an) A[i] = poly(a[i]);
    if (i < bn) B[i] = poly(b[i]);
  } 

  fft(A); fft(B);
  for (int i = 0; i < n; i++) A[i] = A[i]*B[i];
  inverse_fft(A);

  for (int i = 0; i < deg; i++) C[i] = ll(A[i].a+0.5);
  return C;
}

const int N = 2e5+5;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  ll n, m; cin >> n >> m;
  vector<ll> A(N), B(N);
  for (int i = 0; i < n; i++) {
    ll x; cin >> x;
    A[x]++; B[x]++;
  }

  vector<ll> C = mult(A, B);

  ll total = 0;
  for (int i = 2*N; i >= 0; i--) {
    total += i*min(m, C[i]);
    m -= min(m, C[i]);
  }

  cout << total << "\n";

  return 0;
}
