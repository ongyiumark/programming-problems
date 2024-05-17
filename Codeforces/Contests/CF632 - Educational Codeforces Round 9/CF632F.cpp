/*
  a[i][j] <= max(a[i][k], a[k][j])
    means that a[i][j] is equal to the maximum edge in the path between i and j in the MST.

  Build the MST and check the maximum edge in the path between i and j (wiht binary lifting).
*/
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

const int N = 2500+5;
const int LOGN = 15;

vector<piii> edges, mst;
vector<int> graph[N];
int lca[LOGN][N], maxe[LOGN][N];
int a[N][N], ans[N][N];
int dep[N];

struct dsu {
  vector<int> p;
  dsu(int n) : p(n,-1) {}

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
} uf(N);

void dfs(int u, int p) {
  for (int v : graph[u]) {
    if (v == p) continue;
    dep[v] = dep[u]+1;
    dfs(v, u);
  }
}

int compute(int u, int v) {
  if (dep[u] > dep[v]) swap(u,v);
  int up = dep[v] - dep[u];
  int res = 0;
  for (int k = LOGN-1; k >= 0; k--) {
    if ((up>>k)&1) {
      res = max(res, maxe[k][v]);
      v = lca[k][v];
    }
  }

  if (u == v) return res;

  for (int k = LOGN-1; k >= 0; k--) {
    if (lca[k][u] != lca[k][v]) {
      res = max({res, maxe[k][u], maxe[k][v]});
      u = lca[k][u];
      v = lca[k][v];
    }
  }

  res = max({res, maxe[0][u], maxe[0][v]});
  return res;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
      if (i != j) edges.push_back({a[i][j], {i,j}});
    }
  }

  // Check if symmetric and 0 diagonal.
  bool val = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) val &= (a[i][j] == 0);
      else val &= (a[i][j] == a[j][i]);
    }
  }

  if (!val){
    cout << "NOT MAGIC" << endl;
    return 0;
  }

  sort(edges.begin(), edges.end());
  for (auto e : edges){
    auto& [u, v] = e.second;
    int w = e.first;
    if (u > v) swap(u, v);
    if (uf.unite(u,v)) {
      lca[0][v] = u;
      maxe[0][v] = w;

      graph[u].push_back(v);
      graph[v].push_back(u);
    }
  }
  lca[0][0] = 0;
  maxe[0][0] = 0;

  // Binary lifting.
  for (int k = 1; k < LOGN; k++) {
    for (int u = 0; u < n; u++) {
      lca[k][u] = lca[k-1][lca[k-1][u]];
      maxe[k][u] = max(maxe[k-1][u], maxe[k-1][lca[k-1][u]]);
    }
  }

  // Generate depths
  dep[0] = 0;
  dfs(0, -1);

  // Produce expected array
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      ans[i][j] = compute(i,j);
      val &= (ans[i][j] == a[i][j]);
    }
  }

  cout << (val ? "MAGIC" : "NOT MAGIC") << endl;

  
  
  return 0;
}
