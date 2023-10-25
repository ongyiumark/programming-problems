#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int LGN = 18;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n; cin >> n;
  vector<int> c_left(n), c_right(n);
  vector<int> c(n);
  for (int i = 0; i < n; i++) {
    cin >> c[i];
    c[i]--;
    c_left[c[i]]++;
  }
  vector adj(n, vector<pair<int,int>>());
  for (int i = 0; i < n-1; i++) {
    int u, v; cin >> u >> v;
    u--; v--;
    adj[u].push_back({v, i});
    adj[v].push_back({u, i});
  }

  vector par(LGN, vector<int>(n, -1));
  vector subtree(n, 0), depth(n, 0);
  vector heavy(n, pair<int,int>(-1, -1));
  vector parent(n, pair<int,int>());
  vector dfs_num(n, 0);
  int num = 0;
  function<void(int)> dfs = [&](int u) {
    subtree[u] = 1;
    int max_child_size = 0;
    dfs_num[u] = num++;
    for (auto [v, i] : adj[u]) {
      if (v == par[0][u]) continue;
      depth[v] = depth[u]+1;
      par[0][v] = u;
      parent[v] = {u, i};
      dfs(v);
      subtree[u] += subtree[v];
      if (max_child_size < subtree[v]) {
        max_child_size = subtree[v];
        heavy[u] = {v, i};
      }
    }
  };
  par[0][0] = 0;
  parent[0] = {0, -1};
  depth[0] = 0;
  dfs(0);

  // heavy light decomposition
  vector group(n, -1);
  function<void(int, int)> decompose= [&](int u, int p) {
    group[u] = p;
    for (auto [v, i] : adj[u]) {
      if (v == par[0][u]) continue;
      if (v == heavy[u].first) decompose(v, p);
      else decompose(v, v);
    }
  };
  decompose(0, 0);

  vector<int> vals(n);
  vector<int> ans(n-1);
  function<void(int, int, int)> range_add = [&](int u, int v, int val) {
    if (depth[v] < depth[u]) swap(u, v);
    while (group[v] != group[u]) {
      vals[v] -= val;
      v = group[v];
      vals[v] += val;
      int idx = parent[v].second;
      v = parent[v].first;
      ans[idx] += val;
    }
    vals[v] -= val;
    vals[u] += val;
  };

  // binary lifting lca
  for (int k = 1; k < LGN; k++) {
    for (int u = 0; u < n; u++) {
      par[k][u] = par[k-1][par[k-1][u]];
    }
  }
  function<int(int,int)> lca = [&](int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);
    for (int k = LGN-1; k >= 0; k--) {
      if (depth[par[k][a]] < depth[b]) continue;
      a = par[k][a];
    }
    if (a == b) return a;
    for (int k = LGN-1; k >= 0; k--) {
      if (par[k][a] == par[k][b]) continue;
      a = par[k][a];
      b = par[k][b];
    }
    return par[0][a];
  };

  // lca tree
  vector nodes_by_color(n, vector<int>());
  for (int u = 0; u < n; u++) nodes_by_color[c[u]].push_back(u);
  vector tmp_adj(n, vector<int>());
  vector cnts(n, 0);
  vector<bool> in_graph(n, 0);
  for (int i = 0; i < n; i++) {
    int sz = nodes_by_color[i].size();
    if (sz <= 1) continue;
    sort(nodes_by_color[i].begin(), nodes_by_color[i].end(), [&](const int &left, const int &right) {
      return dfs_num[left] < dfs_num[right];
    });

    for (int j = 1; j < sz; j++) {
      int a = nodes_by_color[i][j-1];
      int b = nodes_by_color[i][j];
      int t = lca(a, b);
      
      if (t != a) tmp_adj[t].push_back(a);
      if (t != b) tmp_adj[t].push_back(b);
    }

    vector<pair<int,int>> edges;
    vector<int> results;
    function<void(int)> solve = [&](int u) {
      if (c[u] == i) cnts[u]++;
      for (int v : tmp_adj[u]) {
        solve(v);
        cnts[u] += cnts[v];
      }
      for (int v : tmp_adj[u]) {
        edges.push_back({u, v});
        results.push_back(cnts[v]*(sz-cnts[v]));
      }
    };
    solve(t);

    for (int j = 0; j < (int)edges.size(); j++) {
      auto [u, v] = edges[j];
      range_add(u, v, results[j]);
      cout << "Color: " << i+1 <<  ", Adding: " << u+1 << " " << v+1 << " " << results[j] << endl;
    }

    // reset everything
    vector<int> to_clear;
    function<void(int)> reset = [&](int u) {
      cnts[u] = 0;
      in_graph[u] = false;
      to_clear.push_back(u);
      for (int v : tmp_adj[u]) reset(v);
    };
    reset(t);
    for (int v : to_clear) tmp_adj[v].clear();
  }

  vector<bool> vis(n);
  for (int i = 0; i < n; i++) {
    int u = group[i];
    if (vis[u]) continue;
    vis[u] = true;
    while (u != -1) {
      int pu = parent[u].first;
      int idx = parent[u].second;
      if (group[pu] == group[u] && idx != -1) {
        vals[u] += vals[pu];
        ans[idx] += vals[pu];
      }
      u = heavy[u].first;
    }
  }
  for (int i = 0; i < n-1; i++) {
    cout << ans[i];
    cout << (i+1 < n-1 ? " " : "\n");
  }

  return 0;
}