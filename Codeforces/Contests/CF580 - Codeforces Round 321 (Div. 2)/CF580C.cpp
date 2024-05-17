#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
  cin.tie(0)->sync_with_stdio(false);

  int n, m; cin >> n >> m;
  vector<vector<int>> adj(n+1);
  vector<bool> vis(n+1);
  vector<int> cnt(n+1), a(n+1);
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 0; i < n-1; i++) {
    int u, v; cin >> u >> v;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }

  auto dfs = [&](auto&& dfs, int u) -> int {
    vis[u] = 1;
    cnt[u] = (a[u] ? cnt[u]+a[u] : 0);
    if (cnt[u] > m) return 0;

    if (adj[u].size() == 1 && u != 1) return 1;
    int ret = 0;
    for (int v : adj[u]) {
      if (vis[v]) continue;
      cnt[v] += cnt[u];
      ret += dfs(dfs, v);
    }
    return ret;
  };

  cout << dfs(dfs, 1) << endl;




  return 0; 
}