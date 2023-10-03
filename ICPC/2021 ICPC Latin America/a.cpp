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
const int N = 2e5+5;
ll fact[N], ifact[N];

ll modpow(ll b, ll e) {
  ll ans = 1;
  while(e > 0) {
    if (e&1) ans = ans*b%MOD;
    b = b*b %MOD;
    e >>= 1;
  }
  return ans;
} 

ll modinv(ll x) {
  return modpow(x, MOD-2);
}

ll perm(ll n, ll k) {
  return fact[n]*ifact[n-k]%MOD;
}
ll comb(ll n, ll k) {
  return perm(n, k)*ifact[k]%MOD;
}

vector<vector<int>> adj(N);
ll subgraphs[N], ways[N], par[N];
void dfs(int u) {
  subgraphs[u] = 1;
  for (int &v : adj[u]) {
    if (v == par[u]) continue;
    par[v] = u;
    dfs(v);
    subgraphs[u] += subgraphs[v];
  }

  ways[u] = fact[subgraphs[u]-1];
  for (int &v : adj[u]) {
    if (v == par[u]) continue;
    ways[u] = (ways[u]*ways[v])%MOD;
    ways[u] = (ways[u]*ifact[subgraphs[v]])%MOD;
  }
}

vector<int> results(N);

void rotate(int u, int p) {
  results[u] = ways[u];
  for (int &v : adj[u]) {
    if (v == p) continue;
    // rotate
    ll original_ways_u = ways[u];
    ll original_ways_v = ways[v];
    ll original_subgraph_u = subgraphs[u];
    ll original_subgraph_v = subgraphs[v];

    subgraphs[u] = original_subgraph_u-original_subgraph_v;
    subgraphs[v] = original_subgraph_u;

    ways[u] = ways[u] * ifact[original_subgraph_u-1] % MOD; // divide by (sz-1)!
    ways[u] = ways[u] * fact[subgraphs[u]-1] % MOD; // mutiply by new size
    ways[u] = ways[u] * modinv(original_ways_v * ifact[original_subgraph_v] % MOD) % MOD; // divide contribution of v

    ways[v] = ways[v] * ifact[original_subgraph_v-1] % MOD; // divide by (sz-1)!
    ways[v] = ways[v] * fact[subgraphs[v]-1] % MOD; // mutiply by new size
    ways[v] = ways[v] * ways[u] % MOD * ifact[subgraphs[u]] % MOD; // multiply contribution of u

    rotate(v, u);

    // unrotate
    ways[u] = original_ways_u;
    ways[v] = original_ways_v;
    subgraphs[u] = original_subgraph_u;
    subgraphs[v] = original_subgraph_v;
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  fact[0] = 1;
  for (int i = 1; i < N; i++) fact[i] = i*fact[i-1]%MOD;
  ifact[N-1] = modinv(fact[N-1]);
  for (int i = N-2; i >= 0; i--) ifact[i] = (i+1)*ifact[i+1]%MOD;

  int n; cin >> n;
  for (int i = 0; i < n-1; i++) {
    int a, b; cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  // k = 1
  par[1] = -1;
  dfs(1);
  rotate(1, -1);

  for (int i = 1; i <= n; i++) {
    cout << results[i] << "\n";
  }
  return 0;
}
