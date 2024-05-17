/*
  Represent the costs of the products as a polynomial.
  The answer is the polynomial raise to the kth power.
  
  The sum is possible of the coefficient of the ith degree is nonzero.

  We can apply FFT and raise the transformed points to the kth power,
    but k can be up to 1000. We will have some precision errors.
  
  Instead, we can just manually multiply the polynomial by itself,
    and normalize each time.
  We can speed this up with binary exponentiation.
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define M_PI 3.14159265358979323846

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int>> piii;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int sMAX = 1<<20;
const int N = 1e3+5;
vector<int> ob(N);
vector<int> arr(sMAX);

struct poly {
  ld a, b;
  poly(ld a=0, ld b=0) : a(a), b(b) {}
  poly operator + (const poly& p) const {
    return poly(a+p.a, b+p.b);
  }
  poly operator - (const poly& p) const {
    return poly(a-p.a, b-p.b);
  }
  poly operator * (const poly& p) const {
    return poly(a*p.a-b*p.b, a*p.b+b*p.a);
  }
};

void fft(vector<poly> &in, vector<poly> &p, int i, int j, int n, int s){
  if (n < 1) return;
  if (n == 1) {
    p[j] = in[i];
    return;
  }
  n >>= 1;
  fft(in, p, i, j, n, s << 1);
  fft(in, p, i+s, j+n, n, s << 1);
  poly w(1,0);
  poly wn(cos(M_PI/n),sin(M_PI/n));
  for (int k = 0; k < n; k++) {
    poly even = p[j+k], odd = p[j+k+n];
    p[j+k] = even + w*odd;
    p[j+k+n] = even - w*odd;
    w = w * wn;
  }
}

void fft(vector<poly> &p, int n) {
  vector<poly> f(n); fft(p, f, 0, 0, n, 1);
  copy(f.begin(), f.begin()+n, p.begin());
}

void inverse_fft(vector<poly> &p, int n) {
  for (int i = 0; i < n; i++) {
    p[i].b *= -1;
  }
  fft(p, n);
  for (int i = 0; i < n; i++) {
    p[i].a /= n;
    p[i].b /= -n;
  }
}

int mult(vector<int> &a, int an, vector<int> &b, int bn) {
  int n, deg = an+bn-1;
  for (n = 1; n < deg; n <<= 1);
  vector<poly> A(n), B(n);
  copy(a.begin(), a.begin()+an, A.begin()); 
  copy(b.begin(), b.begin()+bn, B.begin()); 

  fft(A, n); fft(B, n);
  for (int i = 0; i < n; i++) A[i] = A[i]*B[i];
  inverse_fft(A,n);
  for (int i = 0; i < n; i++) {
    if(int(A[i].a + 0.5)) a[i] = 1;
    else a[i] = 0;
  }
  return deg;
}

void polypow(vector<int> &a, int an, int e) {
  vector<int> ans(sMAX);
  ans[0] = 1;
  int ansdeg = 1;
  while (e > 0) {
    if (e&1) {
      ansdeg = mult(ans, ansdeg, a, an);
    }
    an = mult(a, an, a, an);
    e >>= 1;
  }

  for (int i = 0; i < sMAX; i++) {
    a[i] = ans[i];
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, k;
  cin >> n >> k;

  int hi = 0;
  for (int i = 0; i < n; i++) {
    cin >> ob[i];
    arr[ob[i]] = 1;
    hi = max(hi, ob[i]);
  }

  polypow(arr, hi+1, k);

  vector<int> res;
  for (int i = 1; i < sMAX; i++) {
    if (arr[i]) res.push_back(i);
  }

  int sz = res.size();
  for (int i = 0; i < sz; i++) {
    cout << res[i];
    if (i != sz-1) cout << " ";
    else cout << endl;
  }
  
  return 0;
}
