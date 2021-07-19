/*
  Let a be the top position, b be the middle position, and c be the bottom position.
    a,b,c are in a straight line when 2b = a+c.
  
  Suppose we fix b, then we simply need to count how many a,c add up to 2b.
    Let f(a) = 1 if a is present in the top, 0 otherwise.
    Let g(c) = 1 if c is presetn in the bottom, 0 otherwise.
  
  We are interested in the sum over a,c of f(a)*g(c) where a+c = 2b.
  This is a convolution, and can be solved with fft.  
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int>> piii;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const double PI = acos(-1);
struct poly {
  double a, b;
  poly (double a=0, double b=0) : a(a), b(b) {}
  poly operator+(const poly& p) const {return poly(a+p.a, b+p.b);}
  poly operator-(const poly& p) const {return poly(a-p.a, b-p.b);}
  poly operator*(const poly& p) const {return poly(a*p.a-b*p.b, a*p.b+b*p.a);}
};

void fft(poly in[], poly p[], int n, int s){
  if (n < 1) return;
  if (n == 1) {p[0] = in[0]; return;}
  n >>= 1;
  fft(in, p, n, s<<1);
  fft(in + s, p+n, n, s<<1);
  poly w(1), wn(cos(PI/n), sin(PI/n));
  for (int i = 0; i < n; i++){
    poly even = p[i], odd = p[n+i];
    p[i] = even + w*odd;
    p[n+i] = even - w*odd;
    w = w*wn;
  }
}

void fft(poly p[], int n){
  poly *f = new poly[n];
  fft(p, f, n, 1);
  copy(f,f+n,p);
  delete[] f;
}

void inverse_fft(poly p[], int n){
  for (int i = 0; i < n; i++) p[i].b *= -1;
  fft(p,n);
  for (int i = 0; i < n; i++) {
    p[i].a /= n;
    p[i].b /= -1*n;
  }
}

const int N = 5e4+5;
const int M = 3e4;
int x[N], y[N], z[N];
int xx[2*M+5], zz[2*M+5];
int conv[4*M+5];

int mult(int a[], int an, int b[], int bn, int c[]){
  int deg = an+bn-1;
  int n;
  for (n = 1; n < deg; n <<= 1){}
  poly *A = new poly[n], *B = new poly[n];
  copy(a, a+an, A); fill(A+an, A+n, 0);
  copy(b, b+bn, B); fill(B+bn, B+n, 0);
  fft(A, n); fft(B, n);
  for (int i = 0; i < n; i++) A[i] = A[i] * B[i];
  inverse_fft(A, n);
  for (int i = 0; i < deg; i++){
    c[i] = int(A[i].a + 0.5);
  }

  delete[] A, B;
  return deg;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int u,m,l;
  cin >> u;
  for (int i = 0; i < u; i++) cin >> x[i];
  cin >> m;
  for (int i = 0; i < m; i++) cin >> y[i];
  cin >> l;
  for (int i = 0; i < l; i++) cin >> z[i];

  // generating functions;
  memset(xx, 0, sizeof xx);
  memset(zz, 0, sizeof zz);
  for (int i = 0; i < u; i++){
    x[i] += M;
    xx[x[i]] = 1;
  }
  for (int i = 0; i < l; i++){
    z[i] += M;
    zz[z[i]] = 1;
  }

  mult(xx, 2*M+1, zz, 2*M+1, conv);

  int ans = 0;
  for (int i = 0; i < m; i++) {
    y[i] += M;
    int b = 2*y[i];
    ans += conv[b];
  }
  cout << ans << endl;
  return 0;
}
