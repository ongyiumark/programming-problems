#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<bool> find_articulation(vector<vector<int>> &adj) {
  int n = adj.size();
  vector<bool> vis(n), result(n);
  vector<int> tin(n, -1), low(n, -1);

  int timer = 0;
  function<void(int, int)> dfs = [&](int u, int p) {
    tin[u] = low[u] = timer++;
    vis[u] = 1;
    int children = 0;
    for (int &v : adj[u]) {
      if (v == p) continue;
      if (vis[v]) {
        low[u] = min(low[u], tin[v]);
        continue;
      }
      dfs(v, u);
      low[u] = min(low[u], low[v]);
      if (low[v] >= tin[u] && p != -1) result[u] = 1;
      children++;
    }
    if (p == -1 && children > 1) result[u] = 1;
  };
  for (int u = 0; u < n; u++) {
    if (vis[u]) continue;
    dfs(u, -1);
  }
  return result;
}

int main() {
  cin.tie(0)->sync_with_stdio(false);

  int n; 
  int iter = 0;
  while(cin >> n) {
    if (n == 0) break;
    if (iter++ != 0) cout << "\n";
    vector<vector<int>> adj(n);

    vector<string> cities(n);
    for (int i = 0; i < n; i++) cin >> cities[i];
    unordered_map<string, int> city_to_idx;
    for (int i = 0; i < n; i++) city_to_idx[cities[i]] = i;
    int r; cin >> r;

    for (int i = 0; i < r; i++) {
      string su, sv; cin >> su >> sv;
      int u = city_to_idx[su], v = city_to_idx[sv];
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    
    auto is_articulation = find_articulation(adj);
    vector<string> ans;
    for (int i = 0; i < n; i++) {
      if (!is_articulation[i]) continue;
      ans.emplace_back(cities[i]);
    }
    sort(ans.begin(), ans.end());
    int sz = ans.size(); 
    cout << "City map #" << iter << ": " << sz << " camera(s) found\n";
    for (int i = 0; i < sz; i++) {
      cout << ans[i] << "\n";
    }
  }
}