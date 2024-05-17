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

  auto dfs = [&](int s) -> int {
    stack<int> st; st.push(s);
    vector<int> ret(n+1);
    vector<int> par(n+1, -1);
    vis[s] = 1;
    while(!st.empty()) {
      int u = st.top(); st.pop();
      cnt[u] = (a[u] ? cnt[u]+a[u] : 0);
      if (cnt[u] > m) {
        ret[u] = 0;
        continue;
      }

      if (adj[u].size() == 1 && u != 1) {
        ret[u] = 1;
        if (par[u] >= 1) ret[par[u]] += ret[u];
        continue;
      };
      for (int v : adj[u]) {
        if (vis[v]) continue;
        vis[u] = 1;
        cnt[v] += cnt[u];
        par[v] = u;
        st.push(v);
      }
      if (par[u] >= 1) ret[par[u]] += ret[u];
    }
    return ret[s];
  };
  cout << dfs(1) << endl;




  return 0; 
}