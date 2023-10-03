#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long long ld;

vector<vector<int>> adj;
vector<bool> has_nut, vis;

void dfs(int u, int p) {
  vis[u] = true;

  int push_cnt = 0;
  int push_v = u;
  for (int v : adj[u]) {
    if (v == p) continue;
    if (!has_nut[v]) { 
      push_cnt++;
      push_v = v;
    }
  }
  for (int v : adj[u]) {
    if (v == p) continue;
    if (has_nut[u] && push_cnt == 0) continue;

    if (has_nut[u] && push_v == v && push_cnt == 1) {
      has_nut[u] = false;
      has_nut[v] = true;
      dfs(v, u);
      has_nut[v] = false;
      has_nut[u] = true;
    }
    else dfs(v, u);
  }

  if (has_nut[u] && push_cnt == 0) vis[u] = false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m; cin >> n >> m;
  adj.resize(n); 
  vector<bool>(n, 0).swap(has_nut);
  vector<bool>(n, 0).swap(vis);
  for (int i = 0; i < n-1; i++) {
    int u, v; cin >> u >> v;
    u--; v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for (int i = 0; i < m; i++) {
    int x; cin >> x;
    x--;
    has_nut[x] = true;
  }

  dfs(0, -1);
  int ans = 0;
  for (int i = 0; i < n; i++) ans += vis[i];
  cout << ans << "\n";

  return 0;
}