#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod_pow(ll b, ll e, ll m) {
  ll ans = 1; b %= m; 
  while (e > 0) {
    if (e&1) ans = ans*b%m;
    b = b*b%m;
    e >>= 1; 
  }
  return ans;
}

// p                   | deg | g
// 469762049             26    3
// 998244353             23    3
// 1107296257            24    10
// 10000093151233        26    5
// 1000000523862017      26    3
// 1000000000949747713   26    2
template<ll P, ll g>
void ntt(vector<ll> &A, bool invert) {
  // must be power of 2 <= 2^Pdeg
  int n = A.size(); 

  for (int i = 1, j = 0; i < n; i++) {
    int bit = (n >> 1);
    for (; j & bit; bit >>= 1) j ^= bit;
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
    ll n_1 = mod_pow(n, P-2, P);
    for (ll &x : A) x = (x*n_1)%P;
  }
}

template<ll P, ll g>
vector<ll> multiply(vector<ll> p1, vector<ll> p2) {
  int n = 1;
  int deg = p1.size() + p2.size() - 1;
  while (n < deg) n <<= 1;
  vector<ll> A(p1.begin(), p1.end());
  vector<ll> B(p2.begin(), p2.end());
  A.resize(n); B.resize(n);
  ntt<P, g>(A, false); ntt<P, g>(B, false);
  vector<ll> C(n);
  for (int k = 0; k < n; k++)
    C[k] = A[k]*B[k]%P;
  ntt<P, g>(C, true);

  vector<ll> res;
  for (auto &p : C) res.push_back(p);
  res.resize(deg);
  return res;
}

ll primitive_root(ll m) {
  vector<ll> prime_facts;
  // set both to euler totient
  ll tot = m-1, tmp = m-1;
  for (ll i = 2; i*i <= tmp; i++) {
    if (tmp%i == 0) {
      prime_facts.push_back(i);
      while (tmp%i == 0) tmp /= i;
    }
  }
  if (tmp > 1) prime_facts.push_back(tmp);

  for (ll x = 2; x < m; x++) {
    // if (gcd(x, m) != 1) continue;
    bool ok = true;
    for (ll p : prime_facts) 
      if (mod_pow(x, tot/p, m) == 1)
        { ok = false; break; }
    if (ok) return x; 
  }
  return -1; 
}



int main() {
  cin.tie(0)->sync_with_stdio(false);

  int n, m; cin >> n >> m;
  vector<ll> a(n), b(m);
  for (ll &x : a) cin >> x;
  for (ll &x : b) cin >> x;

  const ll P = 998244353, g = 3;
  vector<ll> c = multiply<P, g>(a, b);
  int sz = c.size();
  for (int i = 0; i < sz; i++) {
    cout << c[i] << " \n"[i+1==sz];
  }

  return 0;
}