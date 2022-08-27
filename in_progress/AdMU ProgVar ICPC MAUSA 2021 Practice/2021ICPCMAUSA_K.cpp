#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int>> piii;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 2e5+5;
const int LGN = 20;


ll modpow(ll b, ll e, ll m) {
  ll ans = 1;
  while (e > 0) {
    if (e&1) ans = ans*b%m;
    b = b*b%m;
    e >>= 1;
  }
  return ans;
}

struct node {
  ll idx, up, down;
};

node lca[LGN][N];
int par[N], dep[N];
ll dig[N], mypow10[LGN];
vector<int> graph[N];

void dfs(int u, int d, int p) {
  dep[u] = d;
  for (int v : graph[u]) {
    if (v == p) continue;
    par[v] = u;
    dfs(v, d+1, u);
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n, m, q; cin >> n >> m >> q;

  // Construct tree
  for (int i = 0; i < n-1; i++) {
    int u, v; cin >> u >> v;

    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  par[1] = 1;

  memset(dep, 0, sizeof dep);
  dfs(1, 0, -1);

  // Construct 10^(2^k)
  ll pow2 = 1;
  for (int i = 0; i < LGN; i++) {
    mypow10[i] = modpow(10, pow2, m);
    pow2 *= 2;
  }

  for (int i = 1; i <= n; i++) cin >> dig[i];

  // Binary lifting
  for (int i = 1; i <= n; i++) {
    lca[0][i] = {par[i], dig[i], dig[i]};
  }
  for (int k = 1; k < LGN; k++) {
    for (int i = 1; i <= n; i++) {
      node firsthalf = lca[k-1][i];
      node secondhalf = lca[k-1][firsthalf.idx];
      lca[k][i] = {secondhalf.idx, (firsthalf.up*mypow10[k-1]+secondhalf.up)%m, (secondhalf.down*mypow10[k-1]+firsthalf.down)%m};
    }
  }

  while(q--) {
    int a, b; cin >> a >> b;
    int oga = a, ogb = b;
    ll up = 0, down = 0;
    if (dep[a] > dep[b]) {
      for (int k = LGN-1; k >= 0; k--) {
        node tmp = lca[k][a];
        if (dep[tmp.idx] <= dep[b]) continue;
        up = (up*mypow10[k]+tmp.up)%m;
        a = tmp.idx;
      }

      node tmp = lca[0][a];
      up = (up*mypow10[0]+tmp.up)%m;
      a = tmp.idx;
    }
    else if (dep[b] > dep[a]) {
      for (int k = LGN-1; k >= 0; k--) {
        node tmp = lca[k][b];
        if (dep[tmp.idx] <= dep[a]) continue;
        down = (tmp.down*modpow(10, dep[ogb]-dep[b],m)+down)%m;
        b = tmp.idx;
      }

      node tmp = lca[0][b];
      down = (tmp.down*modpow(10, dep[ogb]-dep[b],m)+down)%m;
      b = tmp.idx;
    }

    assert(dep[a] == dep[b]);

    for (int k = LGN-1; k >= 0; k--) {
      node tmpa = lca[k][a];
      node tmpb = lca[k][b];
      if (tmpa.idx == tmpb.idx) continue;

      up = (up*mypow10[k]+tmpa.up)%m;
      a = tmpa.idx;

      down = (tmpb.down*modpow(10, dep[ogb]-dep[b],m)+down)%m;
      b = tmpb.idx;
    }

    node tmpa = lca[0][a];
    node tmpb = lca[0][b];
    if (a != b) {
      up = (up*mypow10[0]+tmpa.up)%m;
      a = tmpa.idx;

      down = (tmpb.down*modpow(10, dep[ogb]-dep[b],m)+down)%m;
      b = tmpb.idx;
    }

    assert(a == b);
    cout << ((up*10+dig[a])%m*modpow(10, dep[ogb]-dep[b], m)+down)%m << endl; 
  }

  return 0;
}
