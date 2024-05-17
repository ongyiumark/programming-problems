#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> vis; // initialize to all false
vector<vector<pair<int,int>>> adj; // adjacency list
vector<pair<int,int>> nxt;
bool dfs(int u) {
  vis[u] = 1;
  bool cycle = 0;
  for (auto [v,i] : adj[u]) {
    if (vis[v] == 2) continue;
    if (vis[v] == 1) {
      nxt[u] = make_pair(v,i);
      return true;
    }
    cycle |= dfs(v);
    nxt[u] = {v, i};
    if (cycle) return true;
  }
  vis[u] = 2;
  return cycle;
}

int f(int x) {
  return nxt[x].first;
}
pair<int,int> tortoise_hare(int x0) {
  int t = f(x0), h = f(f(x0));
  while (t != h) t = f(t), h = f(f(h));

  int mu = 0; h = x0;
  while (t != h) t = f(t), h = f(h), mu++;

  int lambda = 1; h = f(t);
  while (t != h) h = f(h), lambda++;
  return {mu, lambda};
}

int main() {
  cin.tie(0)->sync_with_stdio(false);

  int n, m; cin >> n >> m;
  adj.resize(n); nxt.resize(n);
  vis.resize(n);
  for (int i = 0; i < m; i++) {
    int u, v; cin >> u >> v;
    adj[u].emplace_back(v, i);
  }

  for (int u = 0; u < n; u++) {
    if (vis[u]) continue;
    bool cycle = dfs(u);
    if (cycle) {
      auto [mu, lamb] = tortoise_hare(u);
      int s = u;
      vector<int> ans;
      mu++;
      while(mu--) {
        s = f(s);
      }
      while(lamb--) {
        ans.push_back(nxt[s].second);
        s = f(s);
      }
      int sz = ans.size();
      cout << sz << "\n";
      for (int i = 0; i < sz; i++) {
        cout << ans[i] << "\n";
      }
      return 0;
    }
  }
  cout << -1 << "\n";


  return 0;
}