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

ll mod_pow(ll b, ll e, ll m) {
  ll ans = 1;
  while (e > 0) {
    if (e&1) ans = ans*b%m;
    b = b*b%m;
    e >>= 1;
  }
  return ans;
}

template<ll P, ll g> 
void ntt(vector<ll> &A, bool invert) {
  int n = A.size();
  for (int i = 1, j = 0; i < n; i++) {
    int bit = (n >> 1);
    for (; j&bit; bit >>= 1) j ^= bit;
    j ^= bit;
    if (i < j) swap(A[i], A[j]);
  }

  ll w0 = mod_pow(g, (P-1)/n, P);
  ll w0_inv = mod_pow(w0, P-2, P);
  for (int cn = 2; cn <= n; cn <<= 1) {
    ll wcn = (invert ? w0_inv : w0);
    for (int i = cn; i < n; i <<= 1)
      wcn = wcn*wcn%P;
    for (int i = 0; i < n; i += cn) {
      ll w = 1;
      for (int j = 0; j < cn/2; j++) {
        ll u = A[i+j]%P, v = A[i+j+cn/2]*w%P;
        A[i+j] = u+v < P ? u+v : u+v-P;
        A[i+j+cn/2] = u-v >= 0 ? u-v : u-v+P;
        w = w*wcn%P;
      }
    } 
  }
  if (invert) {
    ll n_inv = mod_pow(n, P-2, P);
    for (ll &x : A) x = x*n_inv%P; 
  }
}

const ll P = (119<<23)+1;
const ll g = 3; 

vector<ll> multiply(vector<ll> &p1, vector<ll> &p2) {
  int n = 1;
  int deg = p1.size() + p2.size() - 1;
  while (n < deg) n <<= 1;
  vector<ll> A(p1.begin(), p1.end());
  vector<ll> B(p2.begin(), p2.end());
  A.resize(n); B.resize(n);
  ntt<P,g>(A, false); ntt<P,g>(B, false);
  vector<ll> C(n);
  for (int k = 0; k < n; k++) C[k] = A[k]*B[k]%P;
  ntt<P,g>(C, true);

  C.resize(deg);
  return C;
}

int main(){
  cin.tie(0)->sync_with_stdio(false);
  int n, m; cin >> n >> m;
  vector<ll> a(n), b(m);
  for (ll &aa : a) cin >> aa;
  for (ll &bb : b) cin >> bb;

  ll K = 0;
  for (ll &aa : a) K = max(K, aa);
  for (ll &bb : b) K = max(K, bb);
  
  // sum i=0..K, j=0..i of cnt_a(i) cnt_b(j) iCj
  // sum i=0..K, j=0..i of cnt_a(i) cnt_b(j) i!/(j! (i-j)!)
  // sum i=0..K of cnt_a(i) i! (sum j=0..i of cnt_b(j)/(j! (i-j)!))
  // -> sum j=0..i of cnt_b(j)/(j! (i-j)!) 
  //    = sum over j+k=i of cnt_b(j)/(j!k!)
  //    = coef of x**i when cnt_b(j)/j! and 1/k! are multiplied
  vector<ll> cnt_a(K+1), cnt_b(K+1);
  vector<ll> fact(K+1), ifact(K+1);
  for (ll &aa : a) cnt_a[aa]++;
  for (ll &bb : b) cnt_b[bb]++;

  fact[0] = 1;
  for (int i = 1; i <= K; i++) fact[i] = fact[i-1]*i%P;
  ifact[K] = mod_pow(fact[K], P-2, P);
  for (int i = K-1; i >= 0; i--) ifact[i] = ifact[i+1]*(i+1)%P;
  vector<ll> p1(K+1), p2(K+1);

  for (int i = 0; i <= K; i++) {
    p1[i] = cnt_b[i]*ifact[i]%P;
    p2[i] = ifact[i]%P;
  }
  vector<ll> conv = multiply(p1, p2);
  ll ans = 0;
  for (int i = 0; i <= K; i++) {
    ll factor = cnt_a[i] * fact[i]%P;
    ans = (ans + factor*conv[i]%P)%P;
  }
  cout << ans << "\n";

  
  return 0;
}
