#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


ll gcd(ll a, ll b) {
  return b ? gcd(b, a%b) : a;
}

ll mod_pow_long(ll b, ll e, ll m) {
  using i128 = __int128;
  ll ans = 1; b %= m; 
  while (e > 0) {
    if (e&1) ans = i128(ans)*b%m;
    b = i128(b)*b%m;
    e >>= 1; 
  }
  return ans;
}

bool check_composite(ll n, ll a, ll d, int s) {
  ll x = mod_pow_long(a, d, n);
  if (x == 1 || x == n-1) return false;
  for (int r = 1; r < s; r++) {
    x = __int128(x)*x%n;
    if (x == n-1) return false;
  }
  return true;
}


bool is_prime(ll n) {
  if (n < 2) return false;
  int r = 0;
  ll d = n-1;
  while ((d&1) == 0) d >>= 1, r++;

  for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
    if (n == a) return true;
    if (check_composite(n, a, d, r)) return false;
  }
  return true;
}

ll pollard_single(ll n) {
  if (is_prime(n)) return n;
  if (n % 2 == 0) return 2;

  ll st = 0;
  auto f = [&](ll x) { return (__int128(x)*x + st)%n; };
  while (true) {
    st++;
    ll x = st, y = f(x);
    while (true) {
      ll p = gcd(y-x+n, n);
      if (p == 0 || p == n) break;
      if (p != 1) return p;
      x = f(x);
      y = f(f(y));
    }
  }
}

vector<ll> pollard(ll n) {
  if (n == 1) return {};
  ll x = pollard_single(n);
  if (x == n) return {x};
  vector<ll> le = pollard(x);
  vector<ll> ri = pollard(n/x);
  le.insert(le.end(), ri.begin(), ri.end());
  return le;
}

vector<pair<ll,ll>> factorize(ll n) {
  auto facts = pollard(n);
  sort(facts.begin(), facts.end());
  vector<pair<ll,ll>> res;
  int sz = facts.size();
  for (int i = 0, j = 0; i < sz; i = j) {
    while (j < sz && facts[i] == facts[j]) j++;
    res.emplace_back(facts[i], j-i);
  }
  return res;
}

ll primitive_root(ll m) {
  // set both to euler totient
  ll tot = m-1;
  auto facts = factorize(tot);

  for (ll x = 1; x < m; x++) {
    // if (gcd(x, m) != 1) continue;
    bool ok = true;
    for (auto &[p, mult] : facts) 
      if (mod_pow_long(x, tot/p, m) == 1)
        { ok = false; break; }
    if (ok) return x; 
  }
  return -1; 
}

int main() {
  cin.tie(0)->sync_with_stdio(false);

  int  q; cin >> q;
  while(q--) {
    long long p; cin >> p;
    cout << (long long)primitive_root(p) << "\n";
  }


  return 0;
}