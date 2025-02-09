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

const ll MOD = 1e9+7;
ll modpow(ll b, ll e) {
  ll ans = 1;
  while (e > 0) {
    if (e&1) ans = ans*b%MOD;
    b = b*b%MOD;
    e >>= 1;
  }
  return ans;
}

ll modinv(ll x) {
  return modpow(x, MOD-2);
}

ll solve(ll a, ll b) {
  if (a > b) swap(a, b);

  ll left = (1 - modpow(modinv(2), a))%MOD;
  ll right = (1 - modpow(modinv(2), b))%MOD;

  if (left == 0) left = 1;
  ll ans = left*right;
  ans %= MOD;
  if (ans < 0) ans += MOD;
  return ans;
}

ll dfs(ll u, ll p, ll &total, vector<vector<int>> &adj, int n) {
  int subgraph = 1;
  for (int v : adj[u]) {
    if (v == p) continue;
    subgraph += dfs(v, u, total, adj, n);
  }

  total += solve(subgraph, n-subgraph);
  return subgraph;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;
  vector<vector<int>> adj(n);

  for (int i = 0; i < n-1; i++) {
    int u, v; cin >> u >> v;
    u--; v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  ll total = 0;
  dfs(0, -1, total, adj, n);

  total -= n*modinv(2)%MOD;
  total %= MOD;
  if (total < 0) total += MOD;

  cout << total << endl;
  
  return 0;
}
