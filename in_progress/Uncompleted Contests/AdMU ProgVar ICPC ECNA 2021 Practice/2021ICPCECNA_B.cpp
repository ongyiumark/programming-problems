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

const int N = 1e3+5;
const int LGN = 11;
const int INF = 1e9;

int par[LGN][N];
int pages[N];
vector<int> graph[N];
bool vis[N];
int dp[N];
int dep[N];

struct dsu {
  vector<int> p;
  dsu(int n) : p(n, -1) {}
  int find(int x) {
    if (p[x] < 0) return x;
    return p[x] = find(p[x]);
  }

  bool unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return false;
    if (p[a] > p[b]) swap(a,b);
    p[a] += p[b];
    p[b] = a;

    return true;
  }
};
 
void dfs(int u) {
  if (vis[u]) return;
  vis[u] = 1;
  int &ans = dp[u];

  ans = pages[u];
  if (par[0][u] != -1) {
    ans += dp[par[0][u]];
    dep[u] = dep[par[0][u]]+1;
  }

  for (int v : graph[u]) dfs(v);
}

int solve(int a, int b, dsu &uf) {
  int aa = uf.find(a);
  int bb = uf.find(b);
  int ans = dp[a] + dp[b];
  
  if (aa != bb) return ans;

  if (dep[a] < dep[b]) swap(a,b);
  // dep[a] >= dep[b]

  if (dep[a] != dep[b]) {
    for (int k = LGN-1; k >= 0; k--) {
      if (dep[par[k][a]] <= dep[b]) continue;
      a = par[k][a]; 
    }
    a = par[0][a];
    assert(dep[a] == dep[b]);
  }
  
  for (int k = LGN-1; k >= 0; k--) {
    if (par[k][a] == par[k][b]) continue;
    a = par[k][a]; 
    b = par[k][b];
  }
  return ans - dp[a == b ? a : par[0][a]];
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n, m; cin >> n >> m;
  dsu uf(n);
  memset(par, -1, sizeof par);
  for (int i = 0; i < n; i++) cin >> pages[i];
  for (int i = 0; i < m; i++) {
    int u, v; cin >> u >> v;
    u--; v--;

    uf.unite(u,v);
    par[0][v] = u;
    graph[u].push_back(v);
  }

  memset(dp, -1, sizeof dp);
  memset(vis, 0, sizeof vis);
  memset(dep, 0, sizeof dp);
  for (int i = 0; i < n; i++) dfs(i);

  vector<int> culminating;
  for (int i = 0; i < n; i++) {
    if (graph[i].size() == 0) culminating.push_back(i);
  }

  for (int i = 0; i < n; i++) {
    if (par[0][i] == -1) par[0][i] = i;
  }

  for (int k = 1; k < LGN; k++) {
    for (int i = 0; i < n; i++) {
      par[k][i] = par[k-1][par[k-1][i]];
    }
  }

  int ans = INF;
  int k = culminating.size();
  for (int i = 0; i < k; i++) {
    for (int j = i+1; j < k; j++) {
      ans = min(ans,solve(culminating[i],culminating[j], uf));
    }
  }
  cout << ans << endl;
  
  return 0;
}
