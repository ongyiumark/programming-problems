#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m; cin >> n >> m;
  vector<pair<int,int>> edges;
  for (int i = 0; i < m; i++) {
    int u, v; cin >> u >> v;
    u--; v--;
    edges.push_back({u, v});
  }

  vector adj(n, vector<int>());
  for (auto &[u, v] : edges) adj[u].push_back(v);

  // topological sort
  vector<bool> vis(n, false);
  vector<int> toposorted;
  function<void(int)> toposort = [&](int u) {
    vis[u] = true;
    for (int &v : adj[u]) {
      if (vis[v]) continue;
      toposort(v);
    }
    toposorted.push_back(u);
  };
  for (int u = 0; u < n; u++) {
    if (vis[u]) continue;
    toposort(u);
  }
  reverse(toposorted.begin(), toposorted.end());

  // find SCCs
  vis.assign(n, false);
  adj.assign(n, vector<int>());
  for (auto &[u, v] : edges) adj[v].push_back(u);

  vector<int> par(n);
  function<void(int, int)> get_scc = [&](int u, int i) {
    vis[u] = true;
    par[u] = i;
    for (int &v : adj[u]) {
      if (vis[v]) continue;
      get_scc(v, i);
    }
  };
  for (int &u : toposorted) {
    if (vis[u]) continue;
    get_scc(u, u);
  }

  // build SCC graph
  vector<int> in_degree(n), out_degree(n);
  map<pair<int,int>, bool> has_edge;
  for (auto [u, v] : edges) {
    u = par[u]; v = par[v];
    if (u == v) continue;
    if (has_edge.find({u, v}) != has_edge.end()) continue;
    has_edge[{u, v}] = true;
    in_degree[v]++;
    out_degree[u]++;
  }

  int in_degree_zero = 0, out_degree_zero = 0;
  int components = 0;
  for (int i = 0; i < n; i++) {
    if (par[i] != i) continue;
    if (in_degree[i] == 0) in_degree_zero++;
    if (out_degree[i] == 0) out_degree_zero++;
    components++;
  }
  if (components == 1) cout << 0 << "\n";
  else cout << max(in_degree_zero, out_degree_zero) << "\n";



  return 0;
}