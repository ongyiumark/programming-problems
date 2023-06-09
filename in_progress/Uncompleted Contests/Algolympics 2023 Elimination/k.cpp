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

ll modmult(ll a, ll b, ll m) {
  ll ans = (__int128)a*(__int128)b%(__int128)m;
  return ans;
}

ll modpow(ll b, ll e, ll m) {
  ll ans = 1;
  while (e > 0) {
    if (e&1) ans = modmult(ans,b,m);
    b = modmult(b,b,m);
    e >>= 1;
  }
  return ans;
}

ll modinv(ll b, ll p) {
  b %= p;
  return modpow(b, p-2, p);
}

ll legendre_symbol(ll a, ll p) {
  a %= p;
  return modpow(a, (p-1)/2, p);
}

// convert to base 2
vector<bool> convert(ll n) {
  vector<bool> res;
  if (n < 2) {
    res.push_back(n);
    return res;
  }

  while(n != 0) {
    res.push_back(n%2);
    n /= 2;
  }
  reverse(res.begin(), res.end());
  return res;
}

pair<ll, ll> cipolla_mult(pair<ll, ll> x1, pair<ll, ll> x2, ll w, ll p) {
  auto &[a,b] = x1;
  auto &[c,d] = x2;
  return {(modmult(a, c, p) + modmult(modmult(b, d, p),w,p))%p, (modmult(a,d,p) + modmult(b,c,p))%p};
}

ll cipolla(ll n, ll p) {
  n %= p;
  if (n == 0 || n == 1) return n;
  if (legendre_symbol(n, p) != 1) return -1;
  if (p%4 == 3) return modpow(n, (p+1)/4, p);

  // repeat until found
  // probabilistic, expected 2 times
  ll a = 0, w;
  for (ll i = 1; i < p; i++) {
    w = (modmult(i, i, p) - n)%p;
    if (w < 0) w += p;
    if (legendre_symbol(w, p) == p-1) {
      a = i;
      break;
    }
  }

  // solve
  pair<ll, ll> x1 = {a, 1};
  pair<ll, ll> x2 = cipolla_mult(x1, x1, w, p);
  vector<bool> base2 = convert((p+1)/2);

  for (int i = 1; i < (int)base2.size(); i++) {
    bool bit = base2[i];
    if (bit == 0) {
      x2 = cipolla_mult(x2, x1, w, p);
      x1 = cipolla_mult(x1, x1, w, p);
    }
    else {
      x1 = cipolla_mult(x1, x2, w, p);
      x2 = cipolla_mult(x2, x2, w, p);
    }
  }

  //assert(modmult(x1.first, x1.first, p) == n);
  return x1.first;
}

// quadratic formula
pair<ll, ll> get_solutions(ll a, ll p) {
  a %= p;
  if (p == 2) return {0, 1};
  
  ll y1 = cipolla(p+(1-4*a)%p, p);
  ll y2 = p-y1;

  ll x1 = modmult((y1+1),modinv(2, p),p);
  ll x2 = modmult((y2+1),modinv(2, p),p);

  //assert((modmult(x1,x1,p)+a)%p == x1);
  //assert((modmult(x2,x2,p)+a)%p == x2);
  return {x1, x2};
}

const int LIM = 1e5;
vector<bool> sieve(LIM+1);
vector<ll> primes;
ll good_bases[] = {2,325,9375,28178,450775,9780504,1795265022};
bool witness(ll a, ll n) {
  ll t = 0, u = n-1;
  while(u%2 == 0) {
    u >>= 1;
    t += 1;
  }
  ll xp = 1, xi = modpow(a, u, n);
  for (ll i = 0; i < t; i++) {
    xp = xi;
    xi = modmult(xi, xi, n);
    if (xi == 1 && !(xp == 1 || xp == n-1)) return true;
  }
  return xi != 1;
}

bool miller_rabin(ll n) {
  if (n <= 1) return false;
  if (n == 2) return true;
  if (n % 2 == 0) return false;
  if (n <= LIM) return !sieve[n];

  for (const ll &x : good_bases) {
    ll a = x%n;
    if (a == 0) return true;
    if (witness(a, n)) return false;
  }
  return true;
}

void solve_sieve() {
  for (int i = 2; i <= LIM; i++) {
    if (!sieve[i]) primes.push_back(i);
    for (int j = 0; j < (int)primes.size() && i*primes[j] <= LIM; j++) {
      sieve[i*primes[j]] = 1;
      if (i%primes[j] == 0) break;
    }
  }
}

ll mygcd(ll a, ll b) {
  if (b== 0) return a;
  return gcd(b, a%b);
}

ll pollards_rho(ll n) {
  if (n==1) return n;
  if (n%2 == 0) return 2;
 
  ll x = (rand()%(n-2))+2;
  ll y = x;
  ll d = 1;
  ll a = (rand()%(n-1))+1;
  
  int cnt = 0;
  
  while (d == 1) {
    x = (modpow(x, 2, n) + a + n)%n;
 
    y = (modpow(y, 2, n) + a + n)%n;
    y = (modpow(y, 2, n) + a + n)%n;

    d = mygcd(abs(x-y), n);
    if (d == n) return pollards_rho(n);
  }
 
  return d;
}

void factorize(ll n, vector<ll> &factors) {
  if (miller_rabin(n)) {
    factors.push_back(n);
    return;
  }
  
  ll p = pollards_rho(n);

  factorize(p, factors);
  factorize(n/p, factors);
}

ll extended_euclid(ll a, ll b, ll &x, ll &y){
  if (b == 0) {x = 1; y = 0; return a;}
  ll g = extended_euclid(b, a%b, x, y);
  ll z = x - a/b*y;
  x = y; y = z;
  return g;
}

pair<ll, ll> chinese(ll b1, ll m1, ll b2, ll m2) {
  ll x, y; ll g = extended_euclid(m1, m2, x, y);
  if (b1 % g != b2 % g) return {-1, -1};
  ll M = abs(m1/g*m2);

  ll t1 = modmult(modmult(x, b2, M*g), m1, M*g);
  ll t2 = modmult(modmult(y, b1, M*g), m2, M*g);
  ll ans = (t1 + t2)%(M*g)/g%M;
  if (ans < 0) ans += M;
  return {ans, M};
}

pair<ll, ll> chinese_remainder(vector<ll> &b, vector<ll> &m)  {
  pair<ll, ll> ans = {0, 1};
  int n = b.size();
  for (int i = 0; i < n; i++) {
    ans = chinese(b[i], m[i], ans.first, ans.second);
    if (ans.second == -1) break;
  }
  return ans;
}

vector<ll> results;
vector<ll> holder;

void backtrack(int i, vector<pair<ll,ll>> &sols, vector<ll> &factors) {
  int n = sols.size();
  if (i == n) {
    // recover mod n
    pair<ll, ll> ans = chinese_remainder(holder, factors);
    results.push_back(ans.first);
    return;
  }

  if (sols[i].first == sols[i].second) {
    holder.push_back(sols[i].first);
    backtrack(i+1, sols, factors);
    holder.pop_back();
  }
  else {
    holder.push_back(sols[i].first);
    backtrack(i+1, sols, factors);
    holder.pop_back();

    holder.push_back(sols[i].second);
    backtrack(i+1, sols, factors);
    holder.pop_back();
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve_sieve();

  ll n, a; cin >> n >> a;
  vector<ll> factors;
  factorize(n, factors);
  sort(factors.begin(), factors.end());

  // Check if valid
  bool val = 1;
  for (ll p : factors) {
    if (p == 2) val &= (a%p == 0);
    else val &= (legendre_symbol(p+(1-4*a)%p, p) <= 1);
  }

  if (!val) {
    cout << 0 << "\n";
    return 0;
  }

  vector<pair<ll,ll>> sols;
  ll cnt = 0;
  for (ll p : factors) {
    pair<ll, ll> curr_sol = get_solutions(a, p);
    sols.push_back(curr_sol);

    if (curr_sol.first != curr_sol.second) cnt += 1;
    if (cnt >= 20) break;
  }

  if (cnt >= 20) {
    cout << "ABSOLUTELY WAY TOO MANY\n";
    return 0;
  }

  backtrack(0, sols, factors);

  sort(results.begin(), results.end());
  cout << results.size() << "\n";
  for (int i = 0; i < (int)results.size(); i++) {
    cout << results[i] << "\n";
  }

  return 0;
}
