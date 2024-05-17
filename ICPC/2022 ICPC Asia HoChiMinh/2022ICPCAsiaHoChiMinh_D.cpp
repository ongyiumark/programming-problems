#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int INF = 1e9;
vector<vector<int>> adj;
vector<int> color;
bool is_bipartite(int s) {
  color[s] = 0;
  queue<int> q; q.push(s);
  while (!q.empty()) {
    int u = q.front(); q.pop();
    for (int v : adj[u]) {
      if (color[v] == INF) {
        color[v] = 1-color[u];
        q.push(v);
      }
      else if (color[v] == color[u]) return false;
    }
  }
  return true;
}

vector<bool> vis;
vector<int> tmp;
int dfs(int u) {
  vis[u] = 1;
  int sz = 1;
  for (int v : adj[u]) {
    if (vis[v]) continue;
    sz += dfs(v);
  }
  tmp.push_back(u);
  return sz;
}

int main() {
  cin.tie(0)->sync_with_stdio(false);

  int n, m; cin >> n >> m;
  adj.assign(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int u, v; cin >> u >> v;
    u--; v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vis.assign(n, false);
  color.assign(n, INF);
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    if (vis[i]) continue;
    tmp.clear();
    ll sz = dfs(i);

    if (!is_bipartite(i)) ans += sz*sz;
    else {
      ll black = 0, white = 0;
      for (int &x : tmp) {
        black += (color[x] == 1);
        white += (color[x] == 0);
      }
      ans += black*black+ white*white;
    }
  }

  cout << ans << "\n";
}