#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

const ll MOD = 998244353;

int main() {
  cin.tie(0)->sync_with_stdio(false);

  int n; cin >> n;
  vector<int> p(n);
  for (int &x : p) {
    cin >> x;
    x--;
  }

  vector<bool> vis(n);
  function<int(int, int)> dfs = [&](int u, int dep) {
    if (vis[u]) return dep;
    vis[u] = 1;
    return dfs(p[u], dep+1);
  };
  
  auto solve = [&](int m) -> ii {
    auto f = [&](int x) { return (2*x+1)%m; };
    int x0 = 0;

    int t = f(x0), h = f(f(x0));
    while (t != h) t = f(t), h = f(f(h)); 

    int mu = 0; h = x0;
    while (t != h) t = f(t), h = f(h), mu++;

    int lambda = 1; h = f(t);
    while (t != h) h = f(h), lambda++;
    return {mu, lambda};
  };

  auto factorize = [&](ll x) {
    unordered_map<ll,ll> factors;
    for (ll i = 2; i*i <= x; i++) {
      while (x % i == 0) {
        factors[i]++;
        x /= i;
      }
    }
    if (x > 1) factors[x]++;
    return factors;
  };

  auto modpow = [&](ll b, ll e) {
    ll ans = 1;
    while (e > 0) {
      if (e&1) ans = ans*b%MOD;
      b = b*b%MOD;
      e >>= 1;
    }
    return ans;
  };

  unordered_map<ll,ll> lcm_facts;
  ll starts = 0;
  for (int i = 0; i < n; i++) {
    if (vis[i]) continue;
    int sz = dfs(i, 0);

    auto [a, b] = solve(sz);
    starts = max((ll)a, starts);

    auto tmp = factorize(b);
    for (auto &[p, mult] : tmp) {
      lcm_facts[p] = max(lcm_facts[p], mult);
    }
  }

  ll L = 1;
  for (auto &[p, mult] : lcm_facts) {
    L = L*modpow(p, mult)%MOD;
  }

  cout << (L+starts)%MOD << "\n";

  return 0;
}