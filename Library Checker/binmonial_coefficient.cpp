#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int mod_pow(ll b, ll e, int m) {
  int ans = 1; b %= m; 
  while (e > 0) {
    if (e&1) ans = ll(ans)*b%m;
    b = b*b%m;
    e >>= 1; 
  }
  return ans;
}

ll gcd(ll a, ll b) { return (b) ? gcd(b, a%b) : a; }

ll extended_euclid(ll a, ll b, ll& x, ll& y) {
  x = 1, y = 0;
  ll x1 = 0, y1 = 1, a1 = a, b1 = b;
  while (b1) {
    ll q = a1 / b1;
    tie(x, x1) = make_tuple(x1, x - q * x1);
    tie(y, y1) = make_tuple(y1, y - q * y1);
    tie(a1, b1) = make_tuple(b1, a1 - q * b1);
  }
  return a1;
}

struct prime_binom_small_n {
  ll p, q, m; int maxn; 
  vector<ll> g, ig, c, ppows;

  prime_binom_small_n(int maxn, ll p, ll q) 
    : maxn(maxn), p(p), q(q) {
    ppows.resize(q+1);
    ppows[0] = 1;
    for (int i = 1; i <= q; i++) ppows[i] = p*ppows[i-1];
    m = ppows[q];

    g.resize(maxn+1); c.resize(maxn+1);
    ig.resize(maxn+1);
    vector<ll> deprimed(maxn+1);
    g[0] = 1; c[0] = 0;
    for (int i = 1; i <= maxn; i++) {
      if (i % p == 0) {
        deprimed[i] = deprimed[i/p];
        c[i] = c[i/p]+1;
        g[i] = __int128(g[i-1])*deprimed[i]%m;
      }
      else {
        deprimed[i] = i;
        c[i] = 0;
        g[i] = __int128(g[i-1])*deprimed[i]%m;
      }
    }
    for (int i = 1; i <= maxn; i++) c[i] += c[i-1];
    ig[maxn] = mod_pow(g[maxn], m/p*(p-1)-1, m);
    for (int i = maxn-1; i >= 0; i--)
      ig[i] = __int128(deprimed[i+1])*ig[i+1]%m; 
  }

  ll comb(ll n, ll k) {
    if (n < k || n < 0 || k < 0) return 0;
    if (c[n]-c[n-k]-c[k] >= q) return 0;
    ll res = __int128(g[n])*ig[n-k]%m;
    res = __int128(res)*ig[k]%m;
    res = __int128(res)*ppows[c[n]-c[n-k]-c[k]]%m;
    return res;
  }
};

// (mod p^q), p^q <= ~1e8 
struct prime_binom_large_n {
  int p, q, m;
  vector<ll> fact, ifact;
  int delta;
  prime_binom_large_n(int p, int q) : p(p), q(q) {
    m = 1;
    for (int i = 0; i < q; i++) m *= p;

    fact.resize(m); ifact.resize(m);
    fact[0] = ifact[0] = fact[1] = ifact[1] = 1; 
    for (int i = 2; i < m; i++) {
      if (i%p == 0) {
        fact[i] = fact[i-1]; 
        fact[i+1] = fact[i-1]*(i+1)%m; 
        i++;
      }
      else fact[i] = i*fact[i-1]%m;
    }
    
    ifact[m-1] = mod_pow(fact[m-1], m/p*(p-1)-1, m);
    for (int i = m-2; i >= 2; i--) {
      if (i%p == 0) {
        ifact[i] = (i+1)*ifact[i+1]%m;
        ifact[i-1] = ifact[i];
        i--;
      } 
      else ifact[i] = (i+1)*ifact[i+1]%m;
    }

    delta = (p == 2 && q >= 3) ? 1 : m-1;
  }

  int comb(ll n, ll k) {
    if (n < k || n < 0 || k < 0) return 0;
    ll r = n-k;
    int e0 = 0, eq = 0, i = 0;
    ll res = 1;
    while (n > 0) {
      res = res*fact[n%m]%m;
      res = res*ifact[k%m]%m;
      res = res*ifact[r%m]%m;
      n /= p; k /= p; r /= p;
      int eps = n-k-r;
      e0 += eps;
      if (e0 >= q) return 0;
      if (++i >= q) eq += eps;
    }

    res = res*mod_pow(delta, eq, m)%m;
    res = res*mod_pow(p, e0, m)%m;
    return res;
  }
};

pair<ll,ll> crt_single(ll r0, ll m0, ll r1, ll m1) {
  if (m0 < m1) swap(r0, r1), swap(m0, m1);
  if (m0 % m1 == 0 && (r0 % m1 != r1)) 
    return {-1,-1};

  ll im, y;
  ll g = extended_euclid(m0, m1, im, y);
  im %= m1/g; 
  if (im < 0) im += m1/g;

  ll u1 = m1/g;
  if ((r1-r0)%g) return {-1,-1};
  ll x = (r1-r0)/g%u1*im%u1;
  r0 += x*m0; m0 *= u1;
  if (r0 < 0) r0 += m0;
  return {r0, m0};
}
pair<ll,ll> crt(vector<ll> &rems, vector<ll> &mods) {
  int n = rems.size();
  ll r0 = 0, m0 = 1;
  for (int i = 0; i < n; i++) {
    tie(r0, m0) = crt_single(r0, m0, rems[i], mods[i]);
    if (r0 == -1) return {-1, -1};
  }
  return {r0, m0};
}

struct arbitary_mod_binom {
  static int inline maxn = 1e6;
  int mod;
  vector<int> mods;
  vector<prime_binom_large_n> cs;
  vector<prime_binom_small_n> cs_small;


  arbitary_mod_binom(int mod) : mod(mod) {
    int tmp = mod;
    for (int i = 2; i*i <= tmp; i++) {
      if (tmp % i == 0) {
        int cnt = 0, m = 1;
        while (tmp % i == 0) 
          tmp /= i, cnt++, m *= i;
        mods.emplace_back(m);
        cs.emplace_back(i, cnt);
        cs_small.emplace_back(maxn, i, cnt);
      }
    }
    if (tmp > 1) {
      mods.emplace_back(tmp);
      cs.emplace_back(tmp, 1);
      cs_small.emplace_back(maxn, tmp, 1);
    }
  }

  int comb(ll n, ll k) {
    if (mod == 1) return 0;
    vector<ll> rems, ms;
    if (n <= maxn) {
      for (int i = 0; i < (int)cs.size(); i++) {
        rems.emplace_back(cs_small[i].comb(n, k));
        ms.emplace_back(mods[i]);
      }
    }
    else {
      for (int i = 0; i < (int)cs.size(); i++) {
        rems.emplace_back(cs[i].comb(n, k));
        ms.emplace_back(mods[i]);
      }
    }
    return crt(rems, ms).first;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(false);

  int t; cin >> t;
  int m; cin >> m;
  arbitary_mod_binom b(m);
  while (t--) {
    ll n, k; cin >> n >> k;
    cout << b.comb(n, k) << "\n";
  }


  return 0;
}