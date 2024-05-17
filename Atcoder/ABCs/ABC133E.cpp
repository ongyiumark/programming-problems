#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
const ll MOD = 1e9+7;
const ll N = 1e5+5;

vector<ll> fact(N), ifact(N);
ll modpow(ll b, ll e) {
  ll ans = 1;
  while (e > 0) {
    if (e&1) ans = ans*b%MOD;
    b = b*b%MOD;
    e >>= 1;
  }
  return ans;
}
ll inv(ll x) { return modpow(x, MOD-2); }
ll perm(ll n, ll k) {
  if (k > n) return 0;
  return fact[n]*ifact[n-k]%MOD;
}


int main() {
  cin.tie(0)->sync_with_stdio(false);
  fact[0] = 1;
  for (int i = 1; i < N; i++) fact[i] = i*fact[i-1]%MOD;
  ifact[N-1] = inv(fact[N-1]);
  for (int i = N-2; i >= 0; i--) ifact[i] = (i+1)*ifact[i+1]%MOD;
   
  int n; ll k; cin >> n >> k;
  vector<vi> adj(n, vi());
  for (int i = 0; i < n-1; i++) {
    int a, b; cin >> a >> b;
    a--; b--;
    adj[a].emplace_back(b);
    adj[b].emplace_back(a);
  }

  ll ans = k;
  function<void(int, int)> dfs = [&](int u, int p) {
    ans = ans * perm(k-1-(p!=-1), (int)adj[u].size()-(p!=-1))%MOD;
    for (int &v : adj[u]) {
      if (v == p) continue;
      dfs(v, u);
    }
  };
  dfs(0, -1);
  cout << ans << "\n";
  return 0;
}